#include "Ring.h"
#include<iostream>
#include <map>
using namespace std;

Ring::Ring() {

}

Ring::Ring(string name, double cost, double weight) {
	_name = FirstLetterUpper(name);
	_cost = cost;
	_weight = weight;
	_strength = enchantmentBonus();
	_constitution = enchantmentBonus();
	_charisma = enchantmentBonus();
	_wisdom = enchantmentBonus();
	_armorClass = enchantmentBonus();
	setType();
	listEnchantment = enchantment();
}

map<string, int> Ring::enchantment() {
	map<string, int> ring;
	ring.insert(make_pair("Strength", _strength));
	ring.insert(make_pair("Constitution", _constitution));
	ring.insert(make_pair("Charisma", _charisma));
	ring.insert(make_pair("Wisdom", _wisdom));
	ring.insert(make_pair("ArmorClass", _armorClass));
	return ring;
}

void Ring::setType() {
	type = "Ring";
}

