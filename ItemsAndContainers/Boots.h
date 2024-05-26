#pragma once
#include<string>
#include "Items.h"
#include <map>
using namespace std;

/// <summary>
/// Boots class can increase character's armor class and dexterity
/// </summary>
class Boots: public Items
{
public:
	/// <summary>
	/// construcor
	/// </summary>
	Boots();
	/// <summary>
	/// When create a Boots, it must give name, cost and weight of item
	/// </summary>
	/// <param name="name">Boots name </param>
	/// <param name="cost">cost of item </param>
	/// <param name="weight">weight of item</param>
	Boots(string name, double cost, double weight);
protected:
	/// <summary>
	/// Randomly generate a enchantment bonus for armor class and dexterity
	/// </summary>
	/// <returns></returns>
	map<string, int> enchantment();

private:
	int _armorClass; ///< enchantment bonus for armor class
	int _dexterity; ///< enchantment bonus for dexterity class
	/// <summary>
	/// Set type of current item to Boots
	/// </summary>
	void setType(); 
};

