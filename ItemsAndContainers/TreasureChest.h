#pragma once
#include "ItemContainers.h"
#include "CharacterBackpack.h"
/// <summary>
/// Treasure Chest will contains all treasures
/// </summary>
class TreasureChest: public ItemContainers
{
public:
	/// <summary>
	/// TreasureChest constructor
	/// </summary>
	TreasureChest();

	/// Pick up the item treasure chest
	/// @return void
	void pickUpTreasure(Items* item);

	/// Pick up the gold treasure chest
	/// @return void
	void pickUpTreasure(int gold);

	/// Show all treasures item in the treasure chest
	/// @return void
	void showALLTreasures();

	/// Open treasure by treasure name
	/// @return void
	void openTreasure(CharacterBackpack* backpack);

	/// <summary>
	/// Open item treasure 
	/// </summary>
	/// <param name="backpack"></param>
	void openItemTreasure(CharacterBackpack* backpack, string treasureName);

	/// <summary>
	/// Open gold treausre
	/// </summary>
	/// <param name="backpack"></param>
	void openGoldTreasure(CharacterBackpack& backpack, string treasureName);

	int index = 1;
private:
	
	int _order = 1; ///< index to track of the gold treasure
	map<string, int> _treasureGold; ///< list of gold treasure
	
};

