#pragma once
#include "Items.h"
#include <map>
#include <queue>
#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <fstream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[1m\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#include "../Map/nlohmann/json.hpp"
using json = nlohmann::json;
/// <summary>
/// This class represents item container. 
/// The item conatiner ay contain any number of items
/// </summary>
class ItemContainers
{
public:
	/// <summary>
	/// ItemContainers constructor
	/// </summary>
	ItemContainers();

	/// Add a new item to container
	/// @return void
	void addItem(Items &items); 

	/// Get specific Item from container
	/// @return Item Object
	Items getItem(string name);

	/// Remove Item from container
	/// @return void
	void removeItem(Items &items);

	/// Get all the items from current conatiner
	/// @return map<string, Items>
	map<string, Items> getAllItems();

	/// Print all Items to the screnn
	/// @return void 
	void showAllItems();

	/// Get specific item enchantment bonus by their name
	/// @return map<string, int> get encahntment bonus of specific item
	map<string, int> getItemEnchantment(string name);

	/// Remove whitespace from both ends of string
	/// @return string
	string& trim(string& str);

	/// <summary>
	///  convert first letter to upper case
	/// </summary>
	string FirstLetterUpper(string str); 
	void saveItems(string fileName);
	json itemsToJson();
protected:
	map<string, Items> listItems; ///< list of items in current containers
};

