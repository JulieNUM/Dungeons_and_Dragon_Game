#include "Weapon.h"
#include<iostream>
#include <map>
using namespace std;

Weapon::Weapon() {

}

Weapon::Weapon(string name, double cost, double weight) {
	_name = FirstLetterUpper(name);
	_cost = cost;
	_weight = weight;
	
	_attackBonus = enchantmentBonus();
	_damageBonus = enchantmentBonus();
	setType();
	listEnchantment = enchantment();
}

map<string, int> Weapon::enchantment() {
	map<string, int> weapon;
	weapon.insert(make_pair("AttackBonus", _attackBonus));
	weapon.insert(make_pair("DamageBonus", _damageBonus));
	return weapon;
}

void Weapon::setType() {
	type = "Weapon";
}

