#include "Boots.h"
#include<iostream>
#include <map>
using namespace std;

Boots::Boots() {

}

Boots::Boots(string name, double cost, double weight) {
	_name = FirstLetterUpper(name);
	_cost = cost;
	_weight = weight;
	_armorClass = enchantmentBonus();
	_dexterity = enchantmentBonus();
	setType();
	listEnchantment = enchantment();
}

map<string, int> Boots::enchantment() {
	map<string, int> boots;
	boots.insert(make_pair("ArmorClass", _armorClass));
	boots.insert(make_pair("Dexterity", _dexterity));

	return boots;
}

void Boots::setType() {
	type = "Boots";
}

