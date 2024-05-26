#include "Armor.h"
#include<iostream>
#include <map>
using namespace std;

Armor::Armor() {
	
}


Armor::Armor(string name, double cost, double weight) {
	_name = FirstLetterUpper(name);
	_cost = cost;
	_weight = weight;
	_armorClass = enchantmentBonus();
	listEnchantment = enchantment();
	setType();
}

map<string, int> Armor::enchantment() {
	map<string, int> armor;
	armor.insert(make_pair("ArmorClass", _armorClass));
	return armor;
}


void Armor::setType() {
	type = "Armor";
}

