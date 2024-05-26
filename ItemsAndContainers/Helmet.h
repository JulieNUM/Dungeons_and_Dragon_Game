#pragma once
#include<string>
#include "Items.h"
#include <map>
using namespace std;


/// <summary>
/// Helmet class can increase character's armor class, inteligence, wisdom
/// </summary>
class Helmet:public Items
{
public:
	/// <summary>
	/// Helmet construcor
	/// </summary>
	Helmet();
	/// <summary>
	/// When create a Helmet, it must give name, cost and weight of item
	/// </summary>
	/// <param name="name">Helmet name </param>
	/// <param name="cost">cost of item </param>
	/// <param name="weight">weight of item</param>
	Helmet(string name, double cost, double weight);

protected:
	/// <summary>
	/// Randomly generate a enchantment bonus for armor class, inteligence, wisdom
	/// </summary>
	/// <returns></returns>
	map<string, int> enchantment();
private:
	int _intelligence; ///< enchantment bonus for intelligence
	int _wisdom; ///< enchantment bonus for wisdom
	int _armorClass; ///< enchantment bonus for armor class
	/// <summary>
	/// Set type of current item to Helmet
	/// </summary>
	void setType();
};

