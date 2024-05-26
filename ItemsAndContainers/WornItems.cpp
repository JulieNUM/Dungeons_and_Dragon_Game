#include "WornItems.h"
#include "CharacterBackpack.h"
#include "ItemContainers.h"

WornItems::WornItems(AbstractCharacter *characterBase)
{
	// 用于生成log file
	// 用于生成log file
	loggerfile = new LoggerFile("character_log.txt");
	setLoggerFile(loggerfile);
	this->baseCharacter = characterBase;
}

// add item to worn item container
void WornItems::addItem(Items *items, string type)
{
	if (this->baseCharacter->listWornItems.find(type) == this->baseCharacter->listWornItems.end())
	{
		cout << "Added new Item: " << items->getName()+" Type: "+type<< endl;
		this->baseCharacter->listWornItems.insert(make_pair(type, items));
	}
	else
	{
		char input;
		cout << "Do you want to replace current item? y/n ";
		cin >> input;
		if (input == 'y')
		{
			this->baseCharacter->listWornItems.erase(type);
			this->baseCharacter->listWornItems.insert(make_pair(type, items));
			cout << "Replace item successfuly! " << endl;
		}
	}
	notifyLoggerObserver("character added equipment");
}

void WornItems::removeItem(string type)
{
	if (this->baseCharacter->listWornItems.find(type) == this->baseCharacter->listWornItems.end())
	{
		cout << "Can not find this Item !!!" << endl;
	}
	else
	{
		if (baseCharacter->listWornItems.size() == 1)
		{
			cout << "It's your last equipment, you can not remove it " << endl;
		}
		else
		{
			this->baseCharacter->listWornItems.erase(type);
			cout << "You remove " << type << " successfully !!!" << endl;
		}
	}
	notifyLoggerObserver("character removed equipment");
}

void WornItems::printAllItems()
{
	cout << "\033[2J\033[1;1H";
	if (this->baseCharacter->listWornItems.empty())
	{
		cout << "No items in current container ^o^! " << endl;
	}
	else
	{
		for (auto item : this->baseCharacter->listWornItems)
		{
			Items* i = item.second;
			i->printItem();
		}
	}
	notifyLoggerObserver("character printed equipment");

}

map<string, Items*> WornItems::getListWornItems(){
	return this->baseCharacter->listWornItems;
}


void WornItems::saveItems(string filename)
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
json WornItems::itemsToJson()
{
	json cellsArray;
	for (const auto item : this->baseCharacter->listWornItems)
	{
		Items* i = item.second;
		map<std::string, int> items = i->getItemEnchantment();
		json enchantment;
		for (const auto i : items)
		{
			enchantment[i.first] = i.second;
		}
		json cellObject = {
			{"Name", i->getName()},
			{"Type", i->getType()},
			{"Enchantment", enchantment} // Convert enum to int for JSON
		};
		cellsArray.push_back(cellObject);
	}
	return cellsArray;
}
