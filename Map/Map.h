#ifndef MAP_H
#define MAP_H
#include <vector>
#include <list>
#include "MapObserver.h"
#include <iostream>
#include <unordered_map>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;
#include "../Character/LogSubject.hpp"
#include "../Character/LoggerSubject.hpp"
#include "../Character/LoggerObserver.hpp"
#include "../Character/LoggerFile.hpp" 
#include "../Campaign.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[1m\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
// #define Door '|@|'
/**
 * @brief Represents a map grid with various cell types for creating custom maps.
 *
 * This class allows the creation of maps with different cell types such as empty, wall, character,
 * door, start, and end. It provides functions to set cell types, verify map validity, retrieve cell
 * types, and print the map grid.
 */
class MapObserver;

class Map : public LoggerSubject
{
public:
    enum CellType
    {
        EMPTY = ' ',
        WALL = '#',
        CHARACTER = 'C',
        OPPONENT = 'N',
        CHEST = '$',
        DOOR = 182,
        START = 'S',
        END = 'E',
        MONSTER = 'M'
    };

private:
    int width, height;
    std::vector<std::vector<CellType>> grid;
    // initial all subscribe observers
    list<MapObserver*>* _mapObservers;

public:
    /// <summary>
    /// Map constructor
    /// </summary>
    /// <param name="w">width</param>
    /// <param name="h">height</param>
    Map(int w = 10, int h = 10);
    /// <summary>
    /// set value on map
    /// </summary>
    /// <param name="x">x-axis</param>
    /// <param name="y">y-axis</param>
    /// <param name="type">cell type</param>
    void setCell(int x, int y, CellType type);
    bool verifyMap() const;
    /// <summary>
    /// Get the stautus of current map
    /// </summary>
    /// <param name="x">x-axis</param>
    /// <param name="y">y-axis</param>
    /// <returns></returns>
    // char getCell(int x, int y) const;
    /// <summary>
    /// Display map to the console
    /// </summary>
    void printMap() const;
    CellType getCell(int x, int y) const;
    CellType stringToCellType(const std::string& typeStr) const;

    /// <summary>
    ///  Redsiplay the map view  when the value of map change
    /// </summary>
    /// <param name="x">x-axis</param>
    /// <param name="y">y-axis</param>
    void updateMap(int x, int y);
    // Observer design pattern

    /// <summary>
    /// Add observer to map list
    /// </summary>
    /// <param name="map">Map Observer</param>
    virtual void Attach(MapObserver* map);
    /// <summary>
    /// Remove observer from map list
    /// </summary>
    /// <param name="map"></param>
    virtual void Detach(MapObserver* map);
    /// <summary>
    /// When the value of map change, Notify to the observers
    /// </summary>
    virtual void Notify();

    /// <summary>
    /// get list of map observer
    /// </summary>
    /// <returns></returns>
    list<MapObserver*>* getListMapObservers();

    /// @brief save map data to json
    void saveMapToJson(const std::string& filename, Map* map);
    /// @brief  convert current map to json file
    /// @param grid 
    /// @return json
    json mapToJson(const std::vector<std::vector<CellType>>& grid);
    /// @brief get the content store in current map
    /// @return retrun list of map content
    vector<vector<CellType>> getGrid();
    /// @brief get the type of current map postion, wall, monster or empty
    /// @param type enum type
    /// @return current position have 
    string cellTypeToString(CellType type);
    /// @brief get the position of chaaracter in the current map
    /// @return int array for x, y axis
    int* characterPosition();

    // get list of maps that user can play
    vector<string> getJsonFileNamesInCurrentFolder();

    // LoggerFile loggerfile;
    std::vector<LoggerObserver*> loggerobservers;
    LoggerFile* loggerfile;
    // Character():loggerfile(nullptr){};
    void setLoggerFile(LoggerFile* loggerfile)
    {
        this->loggerfile = loggerfile;
        registerLogger(loggerfile);
    }

    void registerLogger(LoggerObserver* logger) override
    {
        loggerobservers.push_back(logger);
    }
    void notifyLoggerObserver(const std::string& message) override
    {
        for (LoggerObserver* logobserver : loggerobservers)
        {
            logobserver->update(message);
        }
    }

    void logMap(string mes);
    std::string getSizeAsString() const;
};

#endif
