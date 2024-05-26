#include "Map.h"
#include <queue>
#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <fstream>
#include "nlohmann/json.hpp"
using namespace std;

//using namespace /std:c++14;

/**
 * @brief Construct a new Map:: Map object
 *
 * @param w
 * @param h
 */
using json = nlohmann::json;

Map::Map(int w, int h) : width(w), height(h), grid(h, std::vector<CellType>(w, EMPTY)) {
    // 用于生成log file
    loggerfile = new LoggerFile("character_log.txt");
    setLoggerFile(loggerfile);
    _mapObservers = new list<MapObserver*>;
}

void Map::setCell(int x, int y, CellType type) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = type;
    }
    else {
        std::cerr << "Error: Coordinates (" << x << ", " << y << ") are out of bounds." << std::endl;
    }
}

bool Map::verifyMap() const {
    // Example implementation of verifyMap that checks for a valid path from START to END.
    // This can be based on a simple search algorithm like BFS.

    std::pair<int, int> start, end;
    bool startFound = false, endFound = false;

    // Locate START and END cells
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (grid[y][x] == START) {
                start = { x, y };
                startFound = true;
            }
            else if (grid[y][x] == END) {
                end = { x, y };
                endFound = true;
            }
        }
    }

    if (!startFound || !endFound) {
        // Missing START or END
        return false;
    }

    // Breadth-first search (BFS) from START to END
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    std::queue<std::pair<int, int>> queue;
    queue.push(start);
    visited[start.second][start.first] = true;

    while (!queue.empty()) {
        auto [cx, cy] = queue.front();
        queue.pop();

        if (cx == end.first && cy == end.second) {
            // Path to END found
            return true;
        }

        // Directions: Up, Down, Left, Right
        std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        for (const auto& [dx, dy] : directions) {
            int nx = cx + dx, ny = cy + dy;

            if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[ny][nx] && grid[ny][nx] != WALL) {
                queue.push({ nx, ny });
                visited[ny][nx] = true;
            }
        }
    }

    // No path found
    return false;
}


void Map::printMap() const {
    // clear console
    cout << "\033[2J\033[1;1H";
    std::cout << "\t\t+";
    for (int k = 0; k < width; ++k) {
        std::cout << "---+";
    }
    std::cout << "\t\t\n";

    for (int i = 0; i < height; ++i) {
        std::cout << "\t\t|";
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == 'C')
                std::cout << " " << RED << static_cast<char>(grid[i][j]) << RESET << " |";
            else if (grid[i][j] == CellType::OPPONENT)
                std::cout << " " << YELLOW << static_cast<char>(grid[i][j]) << RESET << " |";
            else
                std::cout << " " << static_cast<char>(grid[i][j]) << " |";
        }
        std::cout << "\n";

        std::cout << "\t\t+";
        for (int k = 0; k < width; ++k) {
            std::cout << "---+";
        }
        std::cout << "\n";
    }
}

void Map::updateMap(int x, int y)
{
    // system("cls");
    setCell(x, y, CHARACTER);
    Notify();
    notifyLoggerObserver("Upate game map");
}

void Map::Attach(MapObserver* map)
{
    _mapObservers->push_back(map);
    notifyLoggerObserver("Add map observer");
}

void Map::Detach(MapObserver* map)
{
    _mapObservers->remove(map);
}

void Map::Notify()
{
    list<MapObserver*>::iterator i = _mapObservers->begin();
    for (; i != _mapObservers->end(); i++)
        (*i)->Update(this);
}

list<MapObserver*>* Map::getListMapObservers()
{
    return _mapObservers;
}

Map::CellType Map::getCell(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Cell coordinates are out of bounds.");
    }
    return grid[y][x];
}


Map::CellType Map::stringToCellType(const std::string& typeStr) const {
    static const std::unordered_map<std::string, CellType> stringToType = {
        {"EMPTY", EMPTY}, {"WALL", WALL}, {"CHARACTER", CHARACTER},
        {"OPPONENT", OPPONENT}, {"CHEST", CHEST}, {"DOOR", DOOR},
        {"START", START}, {"END", END}, {"MONSTER", MONSTER}
    };

    auto it = stringToType.find(typeStr);
    if (it != stringToType.end()) {
        return it->second;
    }
    else {
        std::cerr << "Warning: Unrecognized cell type '" << typeStr << "'. Defaulting to EMPTY." << std::endl;
        return EMPTY;
    }
}


void Map::saveMapToJson(const string& filename, Map* map) {
    // filename = filename+"Map";
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    vector<vector<Map::CellType>> grid = map->getGrid();
    json data = map->mapToJson(grid);
    file << std::setw(4) << data << std::endl; // Indent JSON for readability
    file.close();
    std::cout << "Save current Map to " << filename << std::endl;
    system("pause");
    notifyLoggerObserver("Save map json file");
}

json Map::mapToJson(const std::vector<std::vector<CellType>>& grid) {
    json result;

    // Add cells
    json cellsArray;
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            json cellObject = {
                {"x", j},
                {"y", i},
                {"type", cellTypeToString(grid[i][j])} // Convert enum to int for JSON
            };
            cellsArray.push_back(cellObject);
        }
    }
    result["cells"] = cellsArray;

    // Add width and height
    result["width"] = grid[0].size(); // Assuming all rows have the same length
    result["height"] = grid.size();

    return result;
}

vector<vector<Map::CellType>> Map::getGrid() {
    return grid;
}

string Map::cellTypeToString(CellType type) {
    switch (type) {
    case CellType::START:
        return "START";
    case CellType::END:
        return "END";
    case CellType::WALL:
        return "WALL";
    case CellType::CHARACTER:
        return "CHARACTER";
    case CellType::OPPONENT:
        return "OPPONENT";
    case CellType::CHEST:
        return "CHEST";
    case CellType::DOOR:
        return "DOOR";
    case CellType::MONSTER:
        return "MONSTER";
    }
    return "EMPTY"; // Handle unknown types if needed
}

int* Map::characterPosition() {
    static int axis[2];
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == CellType::CHARACTER) {
                axis[0] = j;
                axis[1] = i;
                return axis;
            }
        }
    }
    return nullptr;
}

void Map::logMap(string mes) {
    notifyLoggerObserver(mes);
}


// get all map in current folder
vector<string> Map::getJsonFileNamesInCurrentFolder()
{
    vector<string> getAllMaps;
    filesystem::path currentPath = filesystem::current_path();
    for (const auto& entry : filesystem::directory_iterator(currentPath))
    {
        if (entry.path().extension() == ".json")
        {
            getAllMaps.push_back(entry.path().stem().string());
        }
    }
    return getAllMaps;

}
std::string Map::getSizeAsString() const {
    return std::to_string(width) + "x" + std::to_string(height);
}