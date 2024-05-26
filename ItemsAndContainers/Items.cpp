#include "Items.h"
#include<iostream>
#include <map>
using namespace std;


Items::Items(string name, double cost, double weight) {
	_name = FirstLetterUpper(name);
	_cost = cost;
	_weight = weight;
	listEnchantment = enchantment();
}


string Items::FirstLetterUpper(string str)
{
	str[0] = toupper(str[0]);
	for (int i = 1;i < str.length();i++)
	{
		if (str[i] == ' ')
		{
			str[i + 1] = toupper(str[i + 1]);
			break;
		}
	}
	return str;
}

void Items::IsEquipped(bool value){
	_equipped = value;
}

string Items::getName() {
	return _name;
}


// get enchantment bonus +1 to +5
int Items::enchantmentBonus() {
	int bonus = rand() % 5 + 1;
	return bonus;
}

// set equipment to true if worn
void Items::setEquipement() {
	_equipped = true;
}


// get equipment state, true if worn
bool Items::getEquipement() {
	return _equipped;
}

 // virtual code
map<string, int> Items:: enchantment() {
	map<string, int> items;
	return items;
}

void Items::printItem() {
	cout << "\tName: " << _name << " Type: " << type << " ";
	ShowItemEnchantment();
	cout<<endl;

}  

string Items::getType() {
	return type;
}

map<string, int> Items::getItemEnchantment() {
	return listEnchantment;
}

void Items::ShowItemEnchantment() {
	for (map<string, int>::iterator it = listEnchantment.begin(); it != listEnchantment.end(); it++) {
		cout << CYAN <<"("<< (*it).first << " +" << it->second << ") ";
	}
	cout <<RESET;
}