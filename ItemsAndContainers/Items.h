#pragma once
#include<string>
#include <map>
#include<iostream>
using namespace std;
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[1m\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"  
/// <summary>
/// This class represents items class. 
/// And Items can be of type helmet, ring, weapon, shield, armor, and boots.
/// </summary>
class Items
{
public:
	 /// <summary>
	 ///  Item constructor
	 /// </summary>
	 Items() {};
	 
	 /// <summary>
	 /// When create a item, it must give name, cost and weight of item
	 /// </summary>
	 /// <param name="name">name of item</param>
	 /// <param name="cost">cost of item</param>
	 /// <param name="weight">weight of item</param>
	 Items(string name, double cost, double weight);

	 /// This method represents items status, if item is wearing, set status to true
	 /// @retrun void
	 void IsEquipped(bool itemStatus); 

	 /// Get name of current item
	 /// @return string for name of item
	 string getName();

	 /// Set current equipment status to true if item is wearing
	 /// @return void
	 void setEquipement();

	 /// Print basic information of item
	 /// @return void
	 void printItem();

	 /// Get item type, (ex: armor, ring ...)
	 /// @return void
	 string getType();

	 /// Get the enchantment bonus of current item
	 /// @return map<string, int> return the enchatment bonus 
	 map<string, int> getItemEnchantment();

	 /// Show the enchantment bonus of current item on screen
	 /// @retrun void
	 void ShowItemEnchantment();

	 /// Get the current item status, is wearing by character or not
	 /// @retrun bool 
	 bool getEquipement();

protected:
	/// Get list enchantment bonus of current item, ex Intelligence, Wisdom ...
	/// @return map<string, int> return the enchatment bonus 
	map<string, int> enchantment();

	/// <summary>
	///  convert first letter to upper case
	/// </summary>
	string FirstLetterUpper(string str);
	/// Randomly generate enchantment bonus with +1 to +5 for current item
	/// @return int
	int enchantmentBonus();
	bool _equipped = false; ///< bool type,  used to check whether the character is wearing the current item or not
	string _name; ///< this is the name of currenut item
	double _cost=0; ///< this attribute reprsents the cost of current item
	double _weight=0; ///< this is the weight of current item
	string type = ""; ///< this is the type of current itm (ex: Armor)
	map<string, int> listEnchantment; ///< this map represntes enchantment bonus of current item for character's statistics


};

