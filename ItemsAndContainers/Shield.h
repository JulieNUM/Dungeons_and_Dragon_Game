
#pragma once
#include<string>
#include "Items.h"
#include <map>
using namespace std;


/// <summary>
/// Shield class can increase character's armor class
/// </summary>
class Shield: public Items
{
public:
	/// <summary>
	/// Shield construcor
	/// </summary>
	Shield();
	/// <summary>
	/// When create a Shield, it must give name, cost and weight of item
	/// </summary>
	/// <param name="name">Shield name </param>
	/// <param name="cost">cost of item </param>
	/// <param name="weight">weight of item</param>
	Shield(string name, double cost, double weight); 
protected:
	/// <summary>
	/// Randomly generate a enchantment bonus for armor class
	/// </summary>
	/// <returns></returns>
	map<string, int> enchantment();
	


private:
	int _armorClass; ///< enchantment bonus for armor class
	/// <summary>
	/// Set type of current item to Shield
	/// </summary>
	void setType();
};

