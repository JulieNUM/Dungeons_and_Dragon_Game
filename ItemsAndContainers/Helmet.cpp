#include "Helmet.h"
#include<iostream>
#include <map>
using namespace std;

Helmet::Helmet() {

}

Helmet::Helmet(string name, double cost, double weight) {
	_name = FirstLetterUpper(name);
	_cost = cost;
	_weight = weight;

	// initial prperties
	_intelligence = enchantmentBonus();
	_wisdom = enchantmentBonus();
	_armorClass = enchantmentBonus();
	setType();
	listEnchantment = enchantment();
}
map<string, int> Helmet::enchantment() {
	map<string, int> helmet;
	helmet.insert(make_pair("Intelligence", _intelligence));
	helmet.insert(make_pair("Wisdom", _wisdom));
	helmet.insert(make_pair("ArmorClass", _armorClass));
	return helmet;
}

void Helmet::setType() {
	type = "Helmet";
}

