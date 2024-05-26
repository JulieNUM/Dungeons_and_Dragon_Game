#pragma once

#include <string>
#include <map>
#include <iostream>
#include "Character.hpp"
#include "CharacterBuilder.hpp"

/*
This is concrete builder for Bully
*/
class NPCBuilder : public CharacterBuilder {
public:
    NPCBuilder() { cout<<"\nNow your character is NPC...... "<<endl;
    character = new Character();
    cout<<"Now get ready to build your Bully character."<<endl; }

    void buildName(string playerName) override {
        character->setName(playerName);
    }

    void buildAbilityScore() override{ 
        character->setAbilityScore();
    }

    //下边level 到 ArmorClass 都没用，忽略
    void buildLevelUp() override {
       character->setLevel(1);
       character->levelUp();
    }

    void buildDisplayInfo() override {
        character->displayInfo();

    }

    void buildSaveToFile() override {
    }

    void buildLoadFromFile(const string& filename) override {
        character->loadFromFile(filename);
    }


    void buildFighterChoice(int fighterTypeChoice) override{
        character->setfighterChoice(fighterTypeChoice);
    }

    void buildUpdateCharacter() override{
        character->updateCharacter();
    }

    void buildFighterType() override{
        character->setfighterChoice(1);
    }

    void buildExperience() override{
        //character->setExperience();
    }

    void buildArmorValue() override{
        
    }
    
    Character* getResult() {
        return character;
    }

   


private:
    Character* character;
};


