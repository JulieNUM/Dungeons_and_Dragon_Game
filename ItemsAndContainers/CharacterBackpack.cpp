
#include "CharacterBackpack.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Ring.h"
#include "Belt.h"
#include "Boots.h"
#include "Weapon.h"
#include <map>
CharacterBackpack::CharacterBackpack()
{
	createInitialEquipment();
}

// !!! used for wornitem class
// added item to worn item container, remove from backpack
void CharacterBackpack::removeEquipment(Items &items)
{
	string name = items.getName();
	listItems.erase(name);
}

void CharacterBackpack::addGold(int gold)
{
	_gold += gold;
}

// create initial equipment
void CharacterBackpack::createInitialEquipment()
{
	Armor armor("Leather", 10, 10);
	Helmet helmet("Dragon", 100, 10);
	Shield sheild("Shield", 10, 6);
	Ring ring("EvilRing", 22, 1);
	Belt belt("Belt", 18, 5);
	Boots boots("Boots", 15, 4);
	Weapon weapon("Dagger", 50, 1);
	// //
	// Armor armor1("Swift Mail", 10, 10);
	// Helmet helmet1("Dragonhelm", 100, 10);
	// Shield sheild1("Steel Guard", 10, 6);
	// Ring ring1("Dark Band", 22, 1);
	// Belt belt1("Iron Clasp", 18, 5);
	// Boots boots1("Swift Striders", 15, 4);
	// Weapon weapon1("Shadow Blade", 50, 1);

	listItems.insert(make_pair("Dragon", helmet));
	listItems.insert(make_pair("Leather", armor));
	listItems.insert(make_pair("Shield", sheild));
	listItems.insert(make_pair("EvilRing", ring));
	listItems.insert(make_pair("Belt", belt));
	listItems.insert(make_pair("Boots", boots));
	listItems.insert(make_pair("Dagger", weapon));


	// listItems.insert(make_pair("Swift Mail", armor1));
	// listItems.insert(make_pair("Shadow Blade", weapon1));
	// listItems.insert(make_pair("Dragonhelm", helmet1));
	// listItems.insert(make_pair("Steel Guard", sheild1));
	// listItems.insert(make_pair("Dark Band", ring1));
	// listItems.insert(make_pair("Boots", boots1));
	// listItems.insert(make_pair("Shadow Blade", weapon));
}

int CharacterBackpack::getGold()
{
	return _gold;
}

