#include "ItemContainers.h"
#include <map>
#include "Armor.h"
#include "Helmet.h"
#include "Belt.h"
#include "Boots.h"
#include "Ring.h"
#include "Shield.h"
#include "Weapon.h"

using namespace std;
ItemContainers::ItemContainers()
{
}

// add item to container
void ItemContainers::addItem(Items &items)
{
	string name = items.getName();
	listItems.insert(make_pair(name, items));
}

// get item using item name
Items ItemContainers::getItem(string name)
{
	map<string, Items>::iterator position = listItems.find(name);
	if (position != listItems.end())
	{
		return position->second;
	}
	else
	{
		throw invalid_argument("Item not found");
	}
}

// get all list of items
map<string, Items> ItemContainers::getAllItems()
{
	return listItems;
}

void ItemContainers::showAllItems()
{
	if (listItems.empty())
	{
		cout << "No items in current container ^o^! " << endl;
	}
	else
	{
		for (const auto &item : listItems)
		{
			Items i = item.second;
			i.printItem();
			// cout << "Item Enchantment: ";
			// i.ShowItemEnchantment();
			// cout << "" << endl;
		}
	}
}

map<string, int> ItemContainers::getItemEnchantment(string name)
{
	Items item = getItem(name);
	map<string, int> itemEnchantment = item.getItemEnchantment();
	/* print encahtment
	for (map<string, int>::iterator it = itemEnchantment.begin(); it != itemEnchantment.end(); it++) {
		cout << "getItemEnchantment method call : key " << (*it).first << " value: " << it->second << endl;
	}
	*/
	return itemEnchantment;
}

// remove item from item list
void ItemContainers::removeItem(Items &items)
{
	string name = items.getName();
	listItems.erase(name);
}

string &ItemContainers::trim(string &str)
{
	if (str.empty())
		return str;
	str.erase(0, str.find_first_not_of(" "));
	str.erase(str.find_last_not_of(" ") + 1);
	return str;
}

string ItemContainers::FirstLetterUpper(string str)
{
	str[0] = toupper(str[0]);
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str[i + 1] = toupper(str[i + 1]);
			break;
		}
	}
	return str;
}

void ItemContainers::saveItems(string filename)
{
	std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    
    json data = itemsToJson();
    file << std::setw(4) << data << std::endl; // Indent JSON for readability
    file.close();
    // std::cout << "Save current item to " << filename << std::endl;
    // system("pause");
}
json ItemContainers::itemsToJson()
{
	json cellsArray;
	for (const auto &item : listItems)
	{
		Items i = item.second;
		map<std::string, int> items = i.getItemEnchantment();
		json enchantment;
		for (const auto i : items)
		{
			enchantment[i.first] = i.second;
		}
		json cellObject = {
			{"Name", i.getName()},
			{"Type", i.getType()},
			{"Enchantment", enchantment} // Convert enum to int for JSON
		};
		cellsArray.push_back(cellObject);
	}
	return cellsArray;
}
