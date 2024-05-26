#include "Belt.h"
#include<iostream>
#include <map>
using namespace std;

Belt::Belt() {

}
Belt::Belt(string name, double cost, double weight) {
	_name = FirstLetterUpper(name);
	_cost = cost;
	_weight = weight;
	_strength = enchantmentBonus();
	_constitution = enchantmentBonus();
	setType();
	listEnchantment = enchantment();
}

map<string, int> Belt::enchantment() {
	map<string, int> belt;
	belt.insert(make_pair("Strength", _strength));
	belt.insert(make_pair("Constitution", _constitution));

	return belt;
}


void Belt::setType() {
	type = "Belt";
}

