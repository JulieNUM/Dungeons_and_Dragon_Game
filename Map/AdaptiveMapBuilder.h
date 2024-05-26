// AdaptiveMapBuilder.h
#ifndef ADAPTIVEMAPBUILDER_H
#define ADAPTIVEMAPBUILDER_H
#include "Map.h" 
#include "MapBuilder.h"
#include <string>

class AdaptiveMapBuilder {
public:
    /// @brief Construcor
    AdaptiveMapBuilder() = default;
    /// @brief Buidl map from json file
    /// @param filename 
    /// @param playerLevel 
    /// @return map
    Map* buildAdaptiveMapFromJson(const std::string& filename, int playerLevel);
};

#endif // ADAPTIVEMAPBUILDER_H
