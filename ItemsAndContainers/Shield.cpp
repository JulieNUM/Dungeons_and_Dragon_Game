#include "Shield.h"
#include<iostream>
#include <map>
using namespace std;

Shield::Shield() {

}

Shield::Shield(string name, double cost, double weight) {
	_name = name;
	_cost = cost;
	_weight = weight;
	_armorClass = enchantmentBonus();
	setType();
	listEnchantment = enchantment();
}

map<string, int> Shield::enchantment() {
	map<string, int> sheild;
	sheild.insert(make_pair("ArmorClass", _armorClass));
	return sheild;
}

void Shield::setType() {
	type = "Shield";
}

