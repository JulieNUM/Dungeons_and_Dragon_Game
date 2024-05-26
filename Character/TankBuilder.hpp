#ifndef TANK_BUILDER_HPP
#define TANK_BUILDER_HPP

#include <string>
#include <map>
#include <iostream>
#include "Character.hpp"
#include "CharacterBuilder.hpp"

/*
This is concrete builder for Bully
*/
class TankBuilder : public CharacterBuilder
{
public:
    TankBuilder()
    {
        character = new Character();
    }

    void buildName(string playerName) override
    {
        character->setName(playerName);
    }

    void buildAbilityScore() override
    {
        character->setAbilityScore();
    }

    // 下边level 到 ArmorClass 都没用，忽略
    void buildLevelUp() override
    {
        character->setLevel(1);
        character->levelUp();
    }

    void buildeNPCLevelUp(int experience) override
    {
        character->setExperience(experience);
        character->levelUp();
    }

    void buildDisplayInfo() override
    {
        character->displayInfo();
    }

    void buildSaveToFile() override
    {
    }

    void buildLoadFromFile(const string &filename) override
    {
        character->loadFromFile(filename);
    }

    void buildFighterChoice(int fighterTypeChoice) override
    {
        character->setfighterChoice(fighterTypeChoice);
    }

    void buildUpdateCharacter() override
    {
        character->updateCharacter();
    }

    void buildFighterType() override
    {
        character->setfighterChoice(3);
    }

    void buildExperience() override
    {
        // character->setExperience();
    }

    void buildArmorValue() override
    {
    }

    Character *getResult()
    {
        return character;
    }

    void buildNPCAbilityScore() override
    {
        character->setNPCAbilityScore();
    }

    // WornItems *getWornItems() override
    // {
    //     wornItem = new WornItems(character);
    //     return wornItem;
    // }
 GameHelper *getGameHelper() override{
        gameHelper = new GameHelper(character);
        return gameHelper;
    }

private:
    Character *character;
    // WornItems *wornItem;
    GameHelper *gameHelper;

};

#endif // TANK_BUILDER_HPP