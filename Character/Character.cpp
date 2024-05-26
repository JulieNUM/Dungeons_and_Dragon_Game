//!
//! @brief Implementation file for the characterPlay class

#include "Character.hpp"
#include <iostream>
#include <map>
#include "../ItemsAndContainers/Armor.h"
#include "../ItemsAndContainers/Helmet.h"
#include "../ItemsAndContainers/Shield.h"
#include "../ItemsAndContainers/Ring.h"
#include "../ItemsAndContainers/Boots.h"
#include "../ItemsAndContainers/Belt.h"
#include "../ItemsAndContainers/Weapon.h"
using namespace std;

//! @brief Constructor for the Character class.
//! @param  The name of the character.
// Default constructor
Character::Character() : name(""), level(1), experience(0), proficiencyBonus(1), hitPoints(0), armorClass(0)
{
    // 用于生成log file
    loggerfile = new LoggerFile("character_log.txt");
    setLoggerFile(loggerfile);
}

Character::Character(string n) : name(n), level(1), experience(0), proficiencyBonus(1), hitPoints(0), armorClass(10)
{
    loggerfile = new LoggerFile("character_log.txt");
    saveToFile();
    setLoggerFile(loggerfile);
}

Character:: ~Character()
{
    delete loggerfile; // Freeing the memory allocated for loggerfile

    // Freeing the memory allocated for each item in listWornItems
    for (auto entry : listWornItems)
    {
        delete entry.second;
    }
}

void Character::setAbilityScore()
{
    for (int i = 0; i < 6; ++i)
    {
        rollAbilityScore(i);
        initialabilityScores[getAbilityName(i)] = abilityScores[getAbilityName(i)];
        modifiers[getAbilityName(i)] = calculateModifier(abilityScores[getAbilityName(i)]);
        cout << getAbilityName(i) << " ability score: " << abilityScores[getAbilityName(i)] << endl;
    }
    saveToFile();

    notifyLoggerObserver("Set ability scores");
}

void Character::setfighterChoice(int choice)
{

    // chooseCharacterClass(fighterChoice);
    hitPoints = rollHitPoints(10);
    chooseDefaultEquipment(choice);
    switch (choice)
    {
    case 1:
        fighterType = "Bully";
        break;
    case 2:
        fighterType = "Nimble";
        break;
    case 3:
        fighterType = "Tank";
        break;
    default:
        cout << "Unknown";
        break;
    }
    notifyLoggerObserver("Fighter choice: " + fighterType);
}

void Character::armorValue()
{
    armorClass = modifiers["Dexterity"] + equipment["Armor"];
}

//! Rolls hit points based on hit dice and constitution modifier.
//! hit point=hiceDice+constitution modifier
int Character::rollHitPoints(int hitDice)
{
    // cout << "**DEBUG:  constitution: " << modifiers["Constitution"] << endl;
    hitPoints = hitDice + modifiers["Constitution"]; // Constitution modifier

    notifyLoggerObserver("Roll hit points: " + to_string(hitPoints));
    return hitPoints;
}

/*
Level 1=300*0=0
Level 2=300*3^0=300
level 3=300*3^1=900
level 4=300*3^2=2700
...
*/
//! Levels up the character based on accumulated experience points.
//! The character gains increased proficiency bonus, ability score adjustments,
//! and updates hit points, attack bonus, and other attributes accordingly.
void Character::levelUp()
{
    // cout<<"\n**DEBUG Level: "<<level<<endl;
    int levelExp = 300; // Initial experience required for level 2

    while (experience >= levelExp)
    {
        level++;
        if (level % 5 == 0)
        {
            proficiencyBonus++;
            attacksPerRound++;
        }
        // AttackBonud goes by 1 per each level
        attackBonus++;
        // Increase hit points by (1d10 + constitution modifier)
        hitPoints += rollHitPoints(10);
        // Update the experience required for the next level
        levelExp = 300 * pow(3, (level - 1));
    }

    std::string message = "Character leveled up to level " + std::to_string(level);
    notifyLoggerObserver(message);
}

//! Rolls 4 six-sided dice and sums the three highest values to determine ability scores.
//! @param index The index corresponding to the ability score to be rolled.
void Character::rollAbilityScore(int index, bool promptUser)
{
    // clear screen
    //  cout << "\033[2J\033[1;1H";
    //  bool rollAgain=true;
    while (promptUser)
    {
        cout << "\n--" << (index + 1) << ". "
             << "Now rolling the dice for " << getAbilityName(index) << "? (yes/no) ";
        string userInput;
        cin >> userInput;
        if (userInput == "yes")
        {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            srand(seed);
            int diceRolls[4];
            for (int i = 0; i < 4; ++i)
            {
                diceRolls[i] = rand() % 6 + 1;
            }
            sort(diceRolls, diceRolls + 4, greater<int>());
            abilityScores[getAbilityName(index)] = diceRolls[0] + diceRolls[1] + diceRolls[2];
            // cout << "Ability Score for " << getAbilityName(index) << ": " << abilityScores[getAbilityName(index)] << endl;
            promptUser = false; // Exit the loop after successfully rolling the dice
        }
        else if (userInput == "no")
        {
            // Re-roll the dice for the current ability score
            cout << "Re-rolling for " << getAbilityName(index) << endl;
        }
        else
        {
            cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
        }
    }

    notifyLoggerObserver("Roll ability score: " + to_string(abilityScores[getAbilityName(index)]));
}

//! Calculates the modifier for a given ability score.
//! Modifier = (ability Score-10)/2
//! @param score The ability score for which the modifier is calculated.
//! @return The modifier value
int Character::calculateModifier(int score)
{
    return static_cast<int>(std::floor(static_cast<double>(score - 10) / 2));
    notifyLoggerObserver("Calculate modifier: " + to_string(calculateModifier(score)));
}

//! Retrieves the name of an ability based on its index.
//! @param index. The index of the ability.
//! @return The name of th ability
std::string Character::getAbilityName(int index)
{
    switch (index)
    {
    case 0:
        return "Strength";
    case 1:
        return "Dexterity";
    case 2:
        return "Constitution";
    case 3:
        return "Intelligence";
    case 4:
        return "Wisdom";
    case 5:
        return "Charisma";
    default:
        return "";
    }
}

//! Rolls the damage bonus based on strength modifier and proficiency bonus.
//! Damage bonus=strength modifier +proficiency bonus
//! @return The calculated damage bonus.
int Character::rollDamage()
{
    return modifiers["Strength"] + proficiencyBonus;
    notifyLoggerObserver("Roll damage: " + to_string(rollDamage()));
}

/**
 * @brief initialize the equipment
 *
 * @param fighterChoice
 */
void Character::chooseDefaultEquipment(int fighterChoice)
{
    // Apply default equipment based on character class
    Items *armor = new Armor("SwiftMail", 10, 10);
    Items *helmet = new Helmet("Dragonhelm", 100, 10);
    Items *sheild = new Shield("SteelGuard", 10, 6);
    Items *ring = new Ring("DarkBand", 22, 1);
    Items *belt = new Belt("IronClasp", 18, 5);
    Items *boots = new Boots("SwiftStriders", 15, 4);
    Items *weapon = new Weapon("ShadowBlade", 50, 1);

    addItem(armor, "Armor");
    addItem(helmet, "Helmet");
    addItem(sheild, "Shield");
    addItem(ring, "Ring");
    addItem(belt, "Belt");
    addItem(boots, "Boots");
    addItem(weapon, "Weapon");

    
    for (const auto &entry : listWornItems)
    {
        map<std::string, int> items = entry.second->getItemEnchantment();
        for (const auto i : items)
        {
            equipment[i.first] +=i.second;
            // outFile << i.first << " +" << i.second << ", ";
        }
    }
}

//! Displays information about the character, including attributes and class.
void Character::displayInfo()
{
    // cout << "\033[2J\033[1;1H";
    cout << "   Name: " << name << "\n";
    cout << "   Level: " << level << "\n";
    cout << "   Experience: " << experience << "\n";
    cout << "   Proficiency Bonus: +" << proficiencyBonus << "\n";
    hitDice = 10;

    cout << "   Hit Points: " << hitPoints << "\n";
    cout << "   Armor Class: " << armorClass << "\n";
    cout << "   Hit Dice: d" << hitDice << "\n";
    // attackBonus = rollAttack(hitDice);
    cout << "   Attack Bonus: +" << attackBonus << "\n";
    cout << "   Number of attacks: " << attacksPerRound << "\n";
    // Calculate and display the damage bonus
    damageBonus = rollDamage();
    cout << "   Damage Bonus: +" << damageBonus << "\n";
    cout << "   Class: Fighter";

    cout << "\n   Fighter Type: " << fighterType << endl;
    cout << "\n   Equipment: \n";
    // --------------- bugs ------
    for (const auto entry : listWornItems)
    {
        // entry.second
       entry.second->printItem();
    }
    cout << "\n\n"
         << "   Ability Scores:\n";
    for (int i = 0; i < 6; ++i)
    {
        cout << "\t" << getAbilityName(i) << ": " << abilityScores[getAbilityName(i)]
             <<CYAN 
             << " (Modifier: " << modifiers[getAbilityName(i)] << ")"
             <<"(Enchantment +" <<equipment[getAbilityName(i)]<<")"<<RESET<< endl;
    }

    notifyLoggerObserver("Display info");
}

//! only used for CPPUNIT tes and NPC builder pattern
void Character::testRollAbilityScore(int index)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    int diceRolls[4];
    for (int i = 0; i < 4; ++i)
    {
        diceRolls[i] = rand() % 6 + 1;
    }
    sort(diceRolls, diceRolls + 4, greater<int>());
    abilityScores[getAbilityName(index)] = diceRolls[0] + diceRolls[1] + diceRolls[2];
}

void Character::setNPCAbilityScore()
{
    for (int i = 0; i < 6; ++i)
    {
        testRollAbilityScore(i);
        initialabilityScores[getAbilityName(i)] = abilityScores[getAbilityName(i)];
        modifiers[getAbilityName(i)] = calculateModifier(abilityScores[getAbilityName(i)]);
        // cout<< getAbilityName(i)<< " ability score: "<<abilityScores[getAbilityName(i)]<<endl;
    }
    saveToFile();
}

/*
在初始人物的时候，fighter type没有值，升级之后才会出现
*/
void Character::saveToFile()
{
    std::ofstream outFile(name + ".txt");

    if (outFile.is_open())
    {
        outFile << "Name," << name << "\n";
        outFile << "Level," << level << "\n";
        outFile << "Experience," << experience << "\n";
        // Add more information as needed
        outFile << "Proficiency Bonus,+" << proficiencyBonus << "\n";
        outFile << "Hit Points," << hitPoints << "\n";
        outFile << "Armor Class," << armorClass << "\n";
        outFile << "Hit Dice: d," << hitDice << "\n";
        // attackBonus = rollAttack(hitDice);
        outFile << "Attack Bonus," << attackBonus << "\n";
        // Calculate and display the damage bonus
        damageBonus = rollDamage();
        outFile << "Damage Bonus," << damageBonus << "\n";
        outFile << "Fighter type," << fighterType << endl;
        outFile << "\nEquipment:\n";
        for (const auto &entry : listWornItems)
        {
            map<std::string, int> items = entry.second->getItemEnchantment();
            outFile << entry.second->getType() << ":" << entry.second->getName() << "\n";
            for (const auto i : items)
            {
                outFile << i.first << " +" << i.second << ", ";
            }
            outFile << "\n";
        }
        outFile << "\nAbility Scores,";
        for (int i = 0; i < 6; ++i)
        {
            outFile << getAbilityName(i) << " " << abilityScores[getAbilityName(i)] << " " << modifiers[getAbilityName(i)] << ",";
        }

        outFile.close();
    }
    else
    {
        std::cerr << "Error: Unable to open file for writing.\n";
    }

    // notifyLogObserver("Save to file");
}

// 可以读取character from file，并且可以在main driver里直接读取file然后存储到character的每个相对应的值里
void Character::loadFromFile(const string &filename)
{
    // Open the file
    std::ifstream inFile(filename + ".txt");

    if (inFile.is_open())
    {
        string line;

        // Read each line from the file
        while (std::getline(inFile, line))
        {
            // Process each line to extract relevant information
            cout << line << "\n"; // Debug statement

            // Find the comma position to split the line into variable name and value
            size_t commaPos = line.find(",");
            if (commaPos != string::npos && commaPos < line.size() - 1)
            {
                string variableName = line.substr(0, commaPos); // Extract variable name
                string value = line.substr(commaPos + 1);       // Extract value

                // Set the corresponding member variable based on the variable name
                if (variableName == "Name")
                {
                    name = value;
                }
                else if (variableName == "Level")
                {
                    level = stoi(value);
                }
                else if (variableName == "Experience")
                {
                    experience = stoi(value);
                }
                else if (variableName == "Proficiency Bonus")
                {
                    proficiencyBonus = stoi(value);
                }
                else if (variableName == "Hit Points")
                {
                    hitPoints = stoi(value);
                }
                else if (variableName == "Armor Class")
                {
                    armorClass = stoi(value);
                }
                else if (variableName == "Hit Dice")
                {
                    // Assuming the hitDice format is "d,N" where N is the value
                    size_t dPos = value.find("d");
                    if (dPos != string::npos && dPos < value.size() - 1)
                    {
                        // hitDice = stoi(value.substr(dPos + 1));
                        string diceValue = value.substr(dPos + 2);
                        hitDice = stoi(diceValue);
                    }
                }
                else if (variableName == "Attack Bonus")
                {
                    attackBonus = stoi(value);
                }
                else if (variableName == "Damage Bonus")
                {
                    damageBonus = stoi(value);
                }
                else if (variableName == "Fighter type")
                {
                    fighterType = value;
                }

                else if (variableName == "Equipment")
                {
                    // Extract equipment information and store it in the map
                    size_t pos = 0;
                    while ((pos = value.find(',')) != string::npos)
                    {
                        // Extract the substring before the comma
                        string equipmentInfo = value.substr(0, pos);

                        // Find the position of the first digit in the equipmentInfo string
                        size_t digitPos = equipmentInfo.find_first_of("0123456789");
                        if (digitPos != string::npos)
                        {
                            // Extract equipment name and value based on the position of the first digit
                            string equipmentName = equipmentInfo.substr(0, digitPos);
                            int equipmentValue = stoi(equipmentInfo.substr(digitPos));

                            // Store equipment name and value in the map
                            equipment[equipmentName] = equipmentValue;
                        }

                        // Erase the processed substring from the value string
                        value.erase(0, pos + 1);
                    }
                }
                else if (variableName == "Ability Scores")
                {
                    // Extract ability scores information and store it in the maps
                    size_t pos = 0;
                    string delimiter = ",";
                    while ((pos = value.find(delimiter)) != string::npos)
                    {
                        // Extract the substring before the comma
                        string scoreInfo = value.substr(0, pos);

                        // Find the position of the space character in the scoreInfo string
                        size_t spacePos = scoreInfo.find(' ');
                        if (spacePos != string::npos)
                        {
                            // Extract ability name, score, and modifier based on the position of the space character
                            string abilityName = scoreInfo.substr(0, spacePos);
                            string scoreAndModifier = scoreInfo.substr(spacePos + 1);

                            size_t scoreModifierScapcePos = scoreAndModifier.find(' ');
                            if (scoreModifierScapcePos != string::npos)
                            {
                                string scoreValue = scoreAndModifier.substr(0, scoreModifierScapcePos);
                                string modifierValue = scoreAndModifier.substr(scoreModifierScapcePos + 1);
                                int score = stoi(scoreValue);
                                int modifier = stoi(modifierValue);
                                // for(int i=0; i<6;i++){
                                //     abilityScores[getAbilityName(i)]=score;
                                //     modifiers[getAbilityName(i)]=modifier;
                                // }

                                // Store ability score and modifier in the maps

                                // Debugging print statements
                                // cout << "Ability Name: " << abilityName << ", Score: " << score << ", Modifier: " << modifier << endl;

                                abilityScores[abilityName] = score;
                                modifiers[abilityName] = modifier;
                            }
                        }

                        // Erase the processed substring from the value string
                        value.erase(0, pos + delimiter.length());
                    }
                }
            }
        }

        // Close the file after reading
        inFile.close();
    }
    else
    {
        std::cerr << "Error: Unable to open file for reading.\n";
    }
}

int Character::randomRollDice(unsigned seed)
{
    int diceRolls[4];
    for (int i = 0; i < 4; ++i)
    {
        diceRolls[i] = rand() % 6 + 1;
    }
    sort(diceRolls, diceRolls + 4, greater<int>());
    int points = diceRolls[0] + diceRolls[1] + diceRolls[2];
    return points;
}

/**
 * @brief it used to update value by using observer
 *
 */
void Character::updateCharacter()
{

    // Increment experience, level up if necessary, and update hit points
    experience += 1000;
    // hitPoints += 5;

    // Increment each ability score by 1
    for (auto &pair : abilityScores)
    {
        pair.second += 1;
    }

    // Recalculate modifiers based on updated ability scores
    for (auto &pair : abilityScores)
    {
        modifiers[pair.first] = calculateModifier(pair.second);
    }
    levelUp();
    // levelUp()写在前边是因为更新的数据在这里，如果写在consoleObserverCharacter class, 这个就得写在notify后边
    // 但是notifyObserver（）并不能更新原始数据，只是当前数据的copy
    // notifyObserver();

    saveToFile();

    for (CharacterObserver *observer : observers)
    {
        observer->updateView(this);
    }

    notifyLoggerObserver("Update");
}

// add item to worn item container
void Character::addItem(Items *items, string type)
{
    if (items != nullptr)
        listWornItems.insert(make_pair(type, items));
}

void Character::removeItem(string type)
{
    if (type != "")
    {
        listWornItems.erase(type);
        cout << "You remove " << type << " successfully !!!" << endl;
        notifyLoggerObserver("Remove Item");
    }
}

// ------------------ decorator pattern desing -------------
