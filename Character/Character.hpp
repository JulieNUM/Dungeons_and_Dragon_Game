#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "LoggerObserver.hpp"
#include "LoggerSubject.hpp"
#include "LoggerFile.hpp"
#include "Subject.hpp" 
#include <iostream>
#include <fstream>
#include <ostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <vector>
#include "AbstractCharacter.h"


//#include "characterObserver.hpp"
using namespace std;

//! @file
//! @brief Header file containing the class declaration for the characterPlay class.


//! CharacterTest(for cppunit test)
class Character : public Subject, public LoggerSubject, public AbstractCharacter {
    vector<CharacterObserver*> observers;

    friend class CharacterTest;  // Allow CharacterTest to access private members
public:

    // vector<LoggerObserver*> logobservers;
    // LoggerFile loggerfile;

    //LoggerFile loggerfile;
    std::vector<LoggerObserver*> loggerobservers;
    LoggerFile* loggerfile;
    //Character():loggerfile(nullptr){};
    void setLoggerFile(LoggerFile* loggerfile) {
        this->loggerfile = loggerfile;
        registerLogger(loggerfile);
    }


    void registerLogger(LoggerObserver* logger) override {
        loggerobservers.push_back(logger);
    }
    void notifyLoggerObserver(const std::string& message) override {
        for (LoggerObserver* logobserver : loggerobservers) {
            logobserver->update(message);
        }
    }




    Character();
    Character(string n);
    ~Character(); // Declaration of the destructor

    int hitPoints;
    int hitDice = 10;
    int level = 1;
    int fighterChoice;
    int experience;
    string fighterType;

    void setLevel(int initiallevel) { level = initiallevel; }
    int rollHitPoints(int hitDice);
    void levelUp();
    void displayInfo();
    void chooseDefaultEquipment(int choice);
    void setfighterChoice(int choice);
    void armorValue();


    //! Add public setter and getter methods for Cppunit test
    void setExperience(int exp) { experience = exp; }
    void setName(string playerName) { name = playerName; }
    int getLevel() const { return level; }
    int getAbilityScore(const string& ability) const { return abilityScores.at(ability); }
    int getHitPoints() const { return hitPoints; }
    int getExperience() const { return experience; }
    void setHitDice(int dice) { hitDice = dice; }
    int getHitDice() const { return hitDice; }
    void setModifier(const string& ability, int modifier) { modifiers[ability] = modifier; }
    void setProficiencyBonus(int bonus) { proficiencyBonus = bonus; }
    int getEquipment(const std::string& key) const {
        auto it = equipment.find(key);
        if (it != equipment.end()) {
            return it->second;
        }
        else {
            // Return a default value if the key is not found
            return 0;
        }
    }
    int getEquipmentValue(const std::string& equipmentKey) const;
    void rollAbilityScore(int index, bool promptUser = true);
    void testRollAbilityScore(int index);
    void setNPCAbilityScore();


    // //! Observable pattern methods
    // void addObserver(characterObserver* observer);
    // void removeObserver(characterObserver* observer);
    // void notifyObserver();

    void updateCharacter();
    void setAbilityScore(const string abilityName, int score) {
        abilityScores[abilityName] = score;
    }

    int randomRollDice(unsigned seed);

    //! generate character txt file
    void saveToFile();
    void loadFromFile(const string& filename);
    void displayFileContent(const string& filename);


    string getName() const {
        return name;
    }

    void setAbilityScore();


    // ------------------ decorator pattern desing -------------
   /// Add a new item to container
   /// @return void
    void addItem(Items* items, string type);

    /// Remove Item from container
    /// @return void
    void removeItem(string type);
    // ------------------ decorator pattern desing ------------
private:


    string name;
    int proficiencyBonus = 1;
    //int hitPoints;
    int armorClass;
    //int hitDice;
    int attackBonus = 1;
    int damageBonus;
    int attacksPerRound = 1; // Increase number of attacks per round every five levels
    //string equipment;
    std::map<std::string, int> equipment;
    //string equipmentValue;


    map<string, int> abilityScores;
    map<string, int> initialabilityScores;
    map<string, int> modifiers;


    int calculateModifier(int score);
    //void rollHitPoints();
    string getAbilityName(int index);
    int rollAttack(int hitDice);
    int rollDamage();



};

#endif 
// CHARACTER_HPP
