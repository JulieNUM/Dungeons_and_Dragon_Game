/*
the CharacterDirector class acts as a director in the builder pattern,
coordinating the steps of character construction and providing an interface
for displaying character information and loading data from files.
*/
#pragma once
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Character.hpp"
#include "CharacterBuilder.hpp"
#include "BullyBuilder.hpp"
#include "TankBuilder.hpp"
#include "NimbleBuilder.hpp"
#include "../GameHelper.h"
using namespace std;

class characterBuilder;
// class GameHelper;
//  Director class to manage the construction process using the builder
class CharacterDirector
{
public:
    CharacterDirector() : builder(nullptr) {}

    void setBuilder(CharacterBuilder *cb) { builder = cb; }

    
    void construct()
    {
        do
        {
            builder = selectBuilder();
            if (builder == nullptr)
            {
                // cout << "Builder not set.\n";
                return;
            }
            // builder=selectBuilder();
            string playerName;

            cout << "Enter your character's name: ";
            cin >> playerName;
            fileName = playerName;
            builder->buildName(playerName);
            builder->buildFighterType();
            builder->buildAbilityScore();
            builder->buildLevelUp();

            // builder->buildDisplayInfo();
            builder->buildSaveToFile();
            // Call other build methods as needed
            // cout<<"CONSTRUCT DISPLAY"<<endl;

            // cout<<"\n按空格update.";
            // cin.ignore();  // Ignore any previous newline characters in the buffer
            // cin.get();     // Wait for user to press any key
            // cout<<"\n";
            // builder->buildUpdateCharacter();
            character = builder->getResult();
            // wornItems = builder->getWornItems();
            gameHelper = builder->getGameHelper();
            // cout <<"-------------------------------" << endl;
            // wornItems->printAllItems();
            // builder->buildAddItem();

            // bool startGame = false;
            // generate ma p by the option  of users
            // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            // srand(seed);
            gameHelper->oldMapOrCreateNewMap();
            
        } while (createNewCharacter);
    }

    // 在初始人物时，用于选择不同的fighter type，在 CharacterDirector 类中添加一个成员函数，用于选择合适的 builder
    CharacterBuilder *selectBuilder()
    {
        int fighterType;
        gameHelper->printFitherType();
        cin >> fighterType;
        // 根据用户选择的战斗类型构造相应的 builder
        CharacterBuilder *builder = nullptr;
        switch (fighterType)
        {
        case 1:
            cout << "\nNow your fighter type is Bully...... " << endl;
            cout << "Now get ready to build your Bully character." << endl;
            builder = new BullyBuilder();
            break;
        case 2:
            cout << "\nNow your fighter type is Nimble...... " << endl;
            cout << "Now get ready to build your Nimble character." << endl;
            builder = new NimbleBuilder();
            break;
        case 3:
            cout << "\nNow your fighter type is Tank...... " << endl;
            cout << "Now get ready to build your Tank character." << endl;
            builder = new TankBuilder();
            break;
        case 4: 
            cout << "Game end "<< endl;
            system("pause");
            createNewCharacter = false;
        default:
            // cerr << "Invalid builder type selected.\n";
            return nullptr; // 返回空指针表示选择无效
        }

        return builder;
    }

    // 用于随时查看人物信息
    void displayCharacterInfo()
    {
        builder->buildDisplayInfo();
    }

    // Function to select builder based on fighter type extracted from file data
    CharacterBuilder *selectBuilderFromFighterType(const std::string &fighterType)
    {
        if (fighterType == "Bully")
        {
            // cout<<"DEBUG: BULLY 从文档中读取"<<endl;
            return new BullyBuilder();
        }
        else if (fighterType == "Nimble")
        {
            return new NimbleBuilder();
        }
        else if (fighterType == "Tank")
        {
            return new TankBuilder();
        }
        else
        {
            std::cerr << "Invalid fighter type: " << fighterType << std::endl;
            return nullptr;
        }
    }

    
    CharacterBuilder *loadCharacterFromFile(const std::string &filename)
    {
        std::ifstream inFile(filename + ".txt");
        if (!inFile.is_open())
        {
            std::cerr << "Error: Unable to open file for reading.\n";
            return nullptr;
        }

        std::string line;
        std::string fighterType;
        while (std::getline(inFile, line))
        {
            std::istringstream iss(line);
            std::string key, value;
            if (std::getline(iss, key, ',') && std::getline(iss, value))
            {
                if (key == "Fighter type")
                {
                    fighterType = value;
                    break; // Found fighter type, exit loop
                }
            }
        }

        inFile.close();
        CharacterBuilder *builder = selectBuilderFromFighterType(fighterType);
        if (builder == nullptr)
        {
            std::cerr << "Failed to create builder.\n";
            return nullptr;
        }

        builder->buildLoadFromFile(filename);
        setBuilder(builder);

        return builder;
    }

    //This effectively adds the necessary logic to free the pointer in the destructor method
    ~CharacterDirector()
    {
        if (builder != nullptr)
        {
            delete builder;
            builder = nullptr;
        }
    }

    // ！建立NPC时调用这个method
    void NPCConstruct(const string &NPCname, const int &NPCExperience)
    {
        if (builder == nullptr)
        {
            cout << "Builder not set.\n";
            return;
        }
        builder->buildName(NPCname);
        builder->buildFighterType();
        builder->buildNPCAbilityScore();
        builder->buildeNPCLevelUp(NPCExperience);

        // builder->buildDisplayInfo();
        builder->buildSaveToFile();
    }

    string getFileName()
    {
        return fileName;
    }

private:
    CharacterBuilder *builder;
    Character *character;
    string fileName;
    WornItems *wornItems;
    GameHelper *gameHelper;
    bool createNewCharacter =true;
};