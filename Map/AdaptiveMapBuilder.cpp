#include "AdaptiveMapBuilder.h"
#include "Map.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using json = nlohmann::json;

Map* AdaptiveMapBuilder::buildAdaptiveMapFromJson(const std::string& filename, int playerLevel) {
    std::ifstream i(filename);
    if (!i.is_open()) {
        std::cerr << "Could not open map file: " << filename << std::endl;
        return nullptr;
    }

    json j;
    i >> j;

    Map* map = new Map(j["width"].get<int>(), j["height"].get<int>());



    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Loop over the JSON elements to set cells in the map based on their type and player level
    for (const auto& element : j["cells"]) {
        int x = element["x"].get<int>();
        int y = element["y"].get<int>();
        std::string typeStr = element["type"];
        Map::CellType cellType = map->stringToCellType(typeStr);

        // Apply dynamic adaptations based on the player's level and specific conditions
        if (playerLevel >= 10 && typeStr == "EMPTY" && rand() % 3 == 0) {
            cellType = Map::CHEST;
        }
        else if (playerLevel >= 15 && typeStr == "EMPTY" && rand() % 5 == 0) {
            cellType = Map::WALL;
        }

        // Simplify navigation for players with level > 15 by potentially converting walls to doors
        if (playerLevel > 15 && cellType == Map::WALL) {
            cellType = Map::DOOR;
        }

        // Transform some walls into doors for players with level > 18
        if (playerLevel > 18 && cellType == Map::WALL && rand() % 3 == 0) {
            cellType = Map::DOOR;
        }

        // Maintain the OPPONENT type as we're not introducing a STRONG_OPPONENT type
        if (playerLevel > 20 && typeStr == "OPPONENT" && rand() % 4 == 0) {
            // This could be expanded to add more opponents or increase difficulty in some way
            cellType = Map::OPPONENT;
        }

        map->setCell(x, y, cellType);
    }

    return map;
    delete map;
    return nullptr;
}