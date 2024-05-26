#pragma once
#include<string>
#include "Items.h"
#include <map>
using namespace std;

/// <summary>
/// Belt class can increase character's constituion, strength
/// </summary>
class Belt: public Items
{
public:
	/// <summary>
	/// Belt construcor
	/// </summary>
	Belt();
	/// <summary>
	/// When create a Belt, it must give name, cost and weight of item
	/// </summary>
	/// <param name="name">Belt name </param>
	/// <param name="cost">cost of item </param>
	/// <param name="weight">weight of item</param>
	Belt(string name, double cost, double weigth);

protected:
	/// <summary>
	/// Randomly generate a enchantment bonus for strength, constitution
	/// </summary>
	/// <returns></returns>
	map<string, int> enchantment();

private:
	int _constitution;///< enchantment bonus for constitution
	int _strength; ///< enchantment bonus for strength
	/// <summary>
	/// Set type of current item to Belt
	/// </summary>
	void setType();

};

