#include "TreasureChest.h"
#include "CharacterBackpack.h"
#include <string.h>
#include <iostream>

using namespace std;

TreasureChest::TreasureChest()
{
}

// add item treasure to treaure chest
void TreasureChest::pickUpTreasure(Items *item)
{
	string name = item->getName();
	listItems.insert(make_pair(name, *item));
	cout <<YELLOW<< "Congrats, You pick up a treasure!!!" << RESET<<endl;
}

// add gold treasure to treasure chest
void TreasureChest::pickUpTreasure(int gold)
{
	string name = "Treasure" + to_string(_order);
	_treasureGold.insert(make_pair(name, gold));
	_order += 1;
}

void TreasureChest::showALLTreasures()
{
	cout << "\033[2J\033[1;1H";
	if (!listItems.empty())
	{
		cout << "***************************** Item treasure ***********" << endl;
		for (map<string, Items>::iterator it = listItems.begin(); it != listItems.end(); it++)
		{
			cout << "Treasure Item Name: " << (*it).first << " ";
			Items item = it->second;
			item.ShowItemEnchantment();
			cout << endl;
		}
	}
	else
	{
		cout << "Item Treasure Chest is empty!!! Let's go to hunt Monster " << endl;
	}

	if (!_treasureGold.empty())
	{
		cout << "******************************** Gold treasure ***********" << endl;
		for (map<string, int>::iterator it = _treasureGold.begin(); it != _treasureGold.end(); it++)
		{
			cout << "Treasure Name: " << (*it).first << " gold: " << it->second << "$$" << endl;
		}
	}
	else
	{
		cout << "Currently you don'have any gold treasure " << endl;
	}
}

// users can choose which treasure they want to open
void TreasureChest::openTreasure(CharacterBackpack *backpack)
{
	int userInput = 0;
	string treasureName = "";
	showALLTreasures();
	cin.ignore();
	if (!listItems.empty())
	{
		cout << "Select Treasure you want to open? (type the treasure name) ";
		cin >> treasureName;
		openItemTreasure(backpack, treasureName);
	}
}

void TreasureChest::openItemTreasure(CharacterBackpack *backpack, string treasureName)
{
	// treasureName = FirstLetterUpper(treasureName);
	auto it = listItems.find(treasureName);
	if (it != listItems.end())
	{
		Items item = it->second;
		backpack->addItem(item);
		removeItem(item);
		cout << "Item added to your backpack" << endl;
	}
	else
	{
		cout << "Can't find this item " << treasureName << endl;
	}
}

void TreasureChest::openGoldTreasure(CharacterBackpack &backpack, string treasureName)
{
	treasureName = FirstLetterUpper(treasureName);
	auto it = _treasureGold.find(treasureName);
	if (it != _treasureGold.end())
	{
		string name = it->first;
		int gold = it->second;
		backpack.addGold(gold);
		_treasureGold.erase(name);
		cout << "You opened the Gold Treasure +" << gold << "$$" << endl;
	}
	else
	{
		cout << "Can't find Gold Treasure name " << treasureName << endl;
	}
}
