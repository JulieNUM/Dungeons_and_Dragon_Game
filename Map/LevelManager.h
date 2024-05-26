#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "Map.h" 

class LevelManager {
public:
    LevelManager();
    // void loadLevel(int playerLevel);
    // // Other level management functionalities
    Map* loadAdaptiveLevel(int playerLevel, string fileName); // Declare the method that returns a Map pointer
};

#endif // LEVELMANAGER_H
