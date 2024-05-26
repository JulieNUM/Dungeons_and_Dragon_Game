#pragma once
#include<string>
#include "Items.h"
#include <map>
using namespace std;

/// <summary>
/// Armor class can increase character's armor class
/// </summary>
class Armor:public Items
{
public:
	/// <summary>
	/// Armor construcor
	/// </summary>
	Armor();
	/// <summary>
	/// When create a Armor, it must give name, cost and weight of item
	/// </summary>
	/// <param name="name">Armor name </param>
	/// <param name="cost">cost of item </param>
	/// <param name="weight">weight of item</param>
	Armor(string name, double cost, double weight);

protected:
	/// <summary>
	/// Randomly generate a enchantment bonus for armor class
	/// </summary>
	/// <returns></returns>
	map<string, int> enchantment();
private:
	int _armorClass;  ///< enchantment bonus for armor class
	/// <summary>
	/// Set type of current item to Armor
	/// </summary>
	void setType(); 
};

