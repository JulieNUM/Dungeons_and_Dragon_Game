
// /**
//  * @file main.cpp
//  * @version 0.1
//  * @date 2024-02-21
//  * 
//  * @copyright Copyright (c) 2024
//  * 
//  */
// #include "Map.h"
// #include <iostream>
// #include <string>
// #include <cstring>
// #include "../Character/character.hpp"
// #include <iostream> 
// #include "../Character/CharacterObserver.hpp"
// #include "LevelManager.h"
// #include <algorithm>
// #include <chrono>
// #include <ctime>
// using namespace std;

// void PrintMapView(Map& map, int &x, int &y, int rangeX, int rangeY); 
// void createInitialMap();
// void characterPlay(); 
// int getPlayerLevel();
// void displayMainMenu();
// void gameMapBuilder();
// void generateRandomMap();
// int* generateRandomposition(int xRange, int yRange);
// void generateRandomMap();

// int main() { 
//     // characterPlay();
//      cout << "-------- Generate a new Map -------------" << endl;
//      generateRandomMap();
//      gameMapBuilder();
//     return 0;
// }

// /// <summary>
// ///  update view of the map each time character move
// /// </summary>
// /// <param name="map">game map</param>
// /// <param name="x">x-axis</param>
// /// <param name="y">y-axis</param>
// void PrintMapView(Map &map, int &x, int &y, int rangeX, int rangeY) {
//     // Print the map to visualize its layout
//     int moveLeftRight;
//     int moveUpDown;
//     cout << "Character move to left or right (Type number of move ex: -1 or 1): ";
//     cin >> moveLeftRight;
//     cout << "Character move to up and down (Type number of move ex: -1 or 1): ";
//     cin >> moveUpDown;
//     if ((x + moveLeftRight) < 0 || (x + moveLeftRight) >= rangeX || (y + moveUpDown) < 0 || (y + moveUpDown) >= rangeY) {
//         cout << "You have reached the border !!!" << endl;
//         cout << "Don't go too fast. Try to move only one step forward !!!" << endl;
//     }
//     else {
//         // check if it's the wall
//         Map::CellType status = map.getCell(x + moveLeftRight, y + moveUpDown);
//         if (status == '#') {
//             cout << "Can't move, you'll hit the wall !!!!" << endl;
//         }
//         else {
//             // clear cell before character move
//             map.setCell(x, y, Map::EMPTY);
//             x += moveLeftRight;
//             y += moveUpDown;
//             map.updateMap(x, y);
//         }
//     }
// }

// /// <summary>
// /// create new map for the user
// /// </summary>
// void createInitialMap() {
//     // initital Observer in the main function 
//     MapObserver mapOb;
//     // Create a 10x10 map, and the rang of map is X, Y
//     int rangX = 10, rangY = 10;
//     Map gameMap(rangX, rangY);
//     // added map to Observer
//     gameMap.Attach(&mapOb);

//     // intitial charatcer position
//     int x = 3;
//     int y = 3;
//     // Set up the map with a start, end, some walls, and a character
//     gameMap.setCell(0, 0, Map::START);
//     gameMap.setCell(9, 9, Map::END);
//     gameMap.setCell(5, 5, Map::WALL);

//     gameMap.setCell(x, y, Map::CHARACTER);

//     bool exit = true;
//     cout << "Initial Map Layout:\n";
//     gameMap.printMap();


//     while (exit) {
//         PrintMapView(gameMap, x, y, rangX, rangY);
//         string exitC = "";
//         cout << "Type any character to quit or # to continue: ";
//         cin >> exitC;
//         if (exitC != "#") {
//             exit = false;
//         }
//     }
// }

// void characterPlay(){
//         string playerName;
//         int classChoice;
//         bool startGame = true;

//         while (startGame) {
//             // cout << "-----------Welcome to Game------------" << endl;
//             // cout << "\nPlease enter any key to start game.";
//             // cin.ignore();  // Ignore any previous newline characters in the buffer
//             // cin.get();     // Wait for user to press any key
//             // cout << "\n";
//             // //system("clear");
//             // cout << "-------Create your character, please-------" << endl;
//             // //! Get player name
//             // cout << "\nEnter your character's name: ";
//             // cin >> playerName;

//             // //! Get character class choice
//             // cout << "\nChoose character class (1: Wizard, 2: Cleric, 3: Rogue, 4: Fighter): ";
//             // cin >> classChoice;

//             //! Create a character
//             Character charcter;
//             charcter.loadFromFile("T1.txt");
//             // playerCharacter.setClassChoice(classChoice);

//             // // Prompt user to press any key to continue
//             // cout << "\n\nNow that your character has been created, press any key to see your character information....";
//             // cin.ignore();  // Ignore any previous newline characters in the buffer
//             // cin.get();     // Wait for the user to press any key


//             // //! Display initial character gain
//             // cout << "\nInitial Character Info:\n";
//             // playerCharacter.displayInfo();

//             // cout << "\n\nCheck out the updated character information. Please any key to continue..." << endl;
//             // cin.ignore();  // Ignore any previous newline characters in the buffer
//             // cin.get();     // Wait for user to press any key
//             // cout << "\n";
//             // cout << "\n***********************************************\n\n";

//             // // Prompt user to press any key to see updated information
//             // cout << "\n\nNow, you have gained 1000 experience points. Press any key to see your information.";
//             // cin.ignore();  // Ignore any previous newline characters in the buffer
//             // cin.get();     // Wait for user to press any key


//             //! create a observer to update value
//            // ConsoleCharacterObserver consoleObserver;
//            // playerCharacter.addObserver(&consoleObserver);
//            // playerCharacter.updateCharacter();
//             startGame = false;
//         }
// }


// void displayMainMenu() {
//     std::cout << "\nMain Menu:\n";
//     std::cout << "Type 'start' to start a new game.\n";
//     std::cout << "Type 'quit' to exit the game.\n";
//     std::cout << "> ";
// }

// int getPlayerLevel() {
//     // Placeholder function to simulate retrieving a player's level
//     // In a complete application, you might retrieve this from the player's saved data
//     return 5;  // Example player level
// }

// void gameMapBuilder() {
//     LevelManager levelManager;
//     bool gameIsRunning = true;
//     std::string userInput;

//     while (gameIsRunning) {
//         displayMainMenu();
//         std::getline(std::cin, userInput);

//         if (userInput == "start") {
//             int playerLevel = getPlayerLevel(); // Retrieves the player's current level
//             Map* gameMap = levelManager.loadAdaptiveLevel(playerLevel);  // Loads and adapts the map

//             if (gameMap) {
//                 std::cout << "Level loaded successfully for player level " << playerLevel << "!\n";
//                 gameMap->printMap();  // Displays the adapted map
//                 // Here, you might interact with the map (move the character, etc.)
//                 delete gameMap; // Remember to free the allocated Map
//             }
//             else {
//                 std::cerr << "Failed to load the level.\n";
//             }
//         }
//         else if (userInput == "quit") {
//             std::cout << "Exiting game.\n";
//             gameIsRunning = false;
//         }
//         else {
//             std::cout << "Invalid command. Please try again.\n";
//         }
//     }
// }

// void generateRandomMap() {
//     // Create a 10x10 map, and the rang of map is X, Y
//     int rangX = 10, rangY = 10;
//     int* postions=generateRandomposition(rangX, rangY);
//     // initital Observer in the main function 
//     MapObserver mapOb;
//     Map gameMap(rangX, rangY);
//     // added map to Observer
//     gameMap.Attach(&mapOb);

//     // intitial charatcer position
//     int x = postions[0], y = postions[1];

//     // Set up the map with a start, end, some walls, and a character
//     gameMap.setCell(0, 0, Map::START);
//     gameMap.setCell(rangX-1, rangY-1, Map::END);
//     gameMap.setCell(x, y, Map::CHARACTER);

//     // random generate number of mosters
//     int numMonsters = rand() % (rangX + rangY) + 5;
//     for (int i = 0; i < numMonsters; i++)
//     {
//         postions = generateRandomposition(rangX, rangY);
//         gameMap.setCell(postions[0], postions[1], Map::MONSTER);
//     }
   
//     gameMap.setCell(5, 5, Map::WALL);

//     bool exit = true;
//     cout << "Initial Map Layout:\n";
//     gameMap.printMap();
//     while (exit) {
//         PrintMapView(gameMap, x, y, rangX, rangY);
//         string exitC = "";
//         cout << "Type any character to quit or # to continue: ";
//         cin >> exitC;
//         if (exitC != "#") {
//             exit = false;
//         }
//     }

// }

// /// <summary>
// /// this method will generate random position for character and monster
// /// </summary>
// /// <returns></returns>
// int* generateRandomposition(int xRange, int yRange) {
//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//     srand(seed);
//     static int axis[2];
//     axis[0] = rand() % xRange;
//     axis[1] = rand() % yRange;
//     return axis;
// }