#pragma once
#include<string>
#include "Items.h"
#include <map>
using namespace std;


/// <summary>
/// Weapon class can increase character's attackBonus and damageBonus
/// </summary>
class Weapon: public Items
{
public:
	/// <summary>
	/// Weapon construcor
	/// </summary>
	Weapon();
	/// <summary>
	/// When create a Weapon, it must give name, cost and weight of item
	/// </summary>
	/// <param name="name">Weapon name </param>
	/// <param name="cost">cost of item </param>
	/// <param name="weight">weight of item</param>
	Weapon(string name, double cost, double weight);
protected:
	/// <summary>
	/// Randomly generate a enchantment bonus for attackBonus and damageBonus
	/// </summary>
	/// <returns></returns>
	map<string, int> enchantment();
	

private:
	int _attackBonus; ///< enchantment bonus for attackBonus
	int _damageBonus; ///< enchantment bonus for damageBonus
	/// <summary>
	/// Set type of current item to Weapon
	/// </summary>
	void setType();
};

