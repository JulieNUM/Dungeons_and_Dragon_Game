#pragma once
#include<string>
#include "Items.h"
#include <map>
using namespace std;


/// <summary>
/// Ring class can increase character's armor class, strength, constitution, wisdom, charisma
/// </summary>
class Ring: public Items
{
public:
	/// <summary>
	/// Ring construcor
	/// </summary>
	Ring();
	/// <summary>
	/// When create a Ring, it must give name, cost and weight of item
	/// </summary>
	/// <param name="name">Ring name </param>
	/// <param name="cost">cost of item </param>
	/// <param name="weight">weight of item</param>
	Ring(string name, double cost, double weight);
protected:
	/// <summary>
	/// Randomly generate a enchantment bonus for armor class, strength, constitution, wisdom, charisma
	/// </summary>
	/// <returns></returns>
	map<string, int> enchantment();
private:
	int _armorClass; ///< enchantment bonus for armor class
	int _strength; ///< enchantment bonus for strength
	int _constitution; ///< enchantment bonus for constitution
	int _wisdom; ///< enchantment bonus for wisdom
	int _charisma; ///< enchantment bonus for charisma
	/// <summary>
	/// Set type of current item to Ring
	/// </summary>
	void setType(); 
};

