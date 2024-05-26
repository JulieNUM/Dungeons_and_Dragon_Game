#pragma once
#include "ItemContainers.h"

/// <summary>
/// Charaacter Backpack will save all the item that character has
/// </summary>
class CharacterBackpack: public ItemContainers
{
public:
	/// <summary>
	/// CharacterBackpack concstructor
	/// </summary>
	CharacterBackpack();

	/// <summary>
	/// !!! used for wornitem class
	/// added item to worn item container, and remove it from backpack
	/// </summary>
	/// <param name="items">Item object</param>
	void removeEquipment(Items &items);

	/// <summary>
	/// Add gold to backpack
	/// </summary>
	/// <param name="gold"></param>
	void addGold(int gold);

	/// <summary>
	/// Get the number of gold
	/// </summary>
	/// <returns></returns>
	int getGold();

private:
	int _gold; ///< gold that character has
	/// <summary>
	/// Generate initial equipment for character
	/// </summary>
	void createInitialEquipment();
};

