// MapBuilder.h
#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include "Map.h"
#include <string>

class MapBuilder {
public:
    static Map* buildMapFromJson(const std::string& filename);
    static void freeMap(Map* map); // Declaration of freeMap function
};

#endif // MAPBUILDER_H



