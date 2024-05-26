#ifndef CHARACTER_BUILDER_HPP
#define CHARACTER_BUILDER_HPP
#include <string>
#include <map>
#include <iostream>
#include "Character.hpp"
#include "../ItemsAndContainers/WornItems.h"
#include "../GameHelper.h"

class CharacterBuilder
{
public:
    virtual void buildName(string playerName) = 0;
    virtual void buildAbilityScore() = 0; // Character::rollAbilityScore
    virtual void buildExperience() = 0;
    virtual void buildLevelUp() = 0; // Character::levelUp()
    virtual void buildArmorValue() = 0;
    virtual void buildDisplayInfo() = 0;                        // Character::displayInfo()
    virtual void buildSaveToFile() = 0;                         // Character::saveToFile()
    virtual void buildLoadFromFile(const string &filename) = 0; // Character::loadFromFile(const string& filename)
    virtual void buildFighterChoice(int figherTypeChoice) = 0;
    virtual void buildUpdateCharacter() = 0;
    virtual void buildFighterType() = 0; // Character::setfighterChoice(int choice)

    // NPC 设置
    virtual void buildeNPCLevelUp(int NPClevel) = 0;
    virtual void buildNPCAbilityScore() = 0;
    
    virtual ~CharacterBuilder() {}

    Character *getResult() { return character; }

    // virtual  WornItems *getWornItems() = 0;
    virtual GameHelper *getGameHelper() =0;
protected:
    Character *character;
    // WornItems *wornItem;
    GameHelper *gameHelper;
};

#endif
