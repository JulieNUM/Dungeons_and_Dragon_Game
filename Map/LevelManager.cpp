#include "LevelManager.h"
#include "AdaptiveMapBuilder.h"
#include <iostream> 

LevelManager::LevelManager() {}

// This function attempts to load a level adapted to the player's current level
Map* LevelManager::loadAdaptiveLevel(int playerLevel, string fileName) {
    AdaptiveMapBuilder builder;
    fileName = "./"+fileName +".json";
    Map* map = builder.buildAdaptiveMapFromJson(fileName, playerLevel);

    if (!map) {
        std::cerr << "Failed to load adaptive map for level " << playerLevel << "." << std::endl;
    }

    return map; // Returns either a new adaptive map or nullptr if there was an error
}


