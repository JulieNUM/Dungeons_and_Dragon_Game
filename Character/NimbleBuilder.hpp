#ifndef NIMBLE_BUILDER_HPP
#define NIMBLE_BUILDER_HPP

#include <string>
#include <map>
#include <iostream>
#include "Character.hpp"
#include "CharacterBuilder.hpp"

/*
This is concrete builder for Bully
*/
class NimbleBuilder : public CharacterBuilder
{
public:
    NimbleBuilder()
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
        character->setfighterChoice(2);
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

#endif // NIMBLE_BUILDER_HPP