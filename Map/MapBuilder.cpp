#include "MapBuilder.h"
#include "Map.h"
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp" // Make sure this path is correct based on your project setup


using json = nlohmann::json;

Map* MapBuilder::buildMapFromJson(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file for reading: " << filename << std::endl;
        return nullptr;
    }
    
    json j;
    file >> j;
    file.close();

    // int width = j["width"].get<int>();
    // int height = j["height"].get<int>();
    int width = j.value("width", 10); // Default to 10x10 
    int height = j.value("height", 10);

    Map* map = new Map(width, height); // Initialize Map with width and height

    for (const auto& cell : j["cells"]) {
        int x = cell["x"].get<int>();
        int y = cell["y"].get<int>();
        std::string typeStr = cell["type"].get<std::string>();
        Map::CellType type = Map::EMPTY; // Default to EMPTY

        if (typeStr == "START") type = Map::START;
        else if (typeStr == "END") type = Map::END;
        else if (typeStr == "WALL") type = Map::WALL;
        else if (typeStr == "CHARACTER") type = Map::CHARACTER;
        // Handle new cell types here
        else if (typeStr == "OPPONENT") type = Map::OPPONENT;
        else if (typeStr == "CHEST") type = Map::CHEST;
        else if (typeStr == "DOOR") type = Map::DOOR;
        // Add additional conditions for other types as needed
        else if (typeStr == "MONSTER") type = Map::MONSTER;
        map->setCell(x, y, type);
    }

    return map;
}

void MapBuilder::freeMap(Map* map) {
    delete map;
}