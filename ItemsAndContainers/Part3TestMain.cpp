#if false
#include<iostream>
#include<map>
#include "Armor.h"
#include "CharacterBackpack.h"
#include "WornItems.h"
#include "Ring.h"
#include "TreasureChest.h"
using namespace std;

int main() {
	/// !!!!! important, seed for random, don't forget to put, don't move or delete
	srand(time(NULL));
	// Initial CharacterBackpack container
	CharacterBackpack c1;
	// Initial WornItems container
	WornItems w1;
	// wear initial equipemnt
	w1.initialWearItems(c1);
	
	cout << "Worn Items:" << endl;
	w1.showAllItems();
	
	cout << "Backpack: " << endl;
	c1.showAllItems();
	
	cout << "==========================================" << endl;
	// remove equipemnt
	w1.removeEquipment("Leather", c1);
	cout << "Worn Items:" << endl;
	w1.showAllItems();
	cout << "Backpack: " << endl;
	c1.showAllItems();

	 
	
	//w1.getItemEnchantment("Hel");
	

	// debug
	// treasure
	// comment method

	cout << "============== treasure section ===================" << endl;
	Ring ring("gold ging", 10, 2);
	int gold = 10;
	TreasureChest treasureChest;
	treasureChest.pickUpTreasure(ring);
	treasureChest.pickUpTreasure(gold);
//	treasureChest.showALLTreasures();
	treasureChest.openTreasure(c1);

	return 0;
}
#endif