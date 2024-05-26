#pragma once
#include "ItemContainers.h"
#include "Items.h"
#include "CharacterBackpack.h"
#include "Decorator/ItemDecorator.h"
#include "../Character/LogSubject.hpp"
#include "../Character/LoggerSubject.hpp"
#include "../Character/LoggerObserver.hpp"
#include "../Character/LoggerFile.hpp"

/// <summary>
/// This class represents all the items that character is wearing
/// </summary>

class WornItems : public ItemDecorator, public LoggerSubject
{
public:
	/// <summary>
	/// WornItems Construnctor
	/// </summary>
	WornItems(AbstractCharacter *ab);

	/// Add a new item to container
	/// @return void
	void addItem(Items *items, string type);

	/// Remove Item from container
	/// @return void
	void removeItem(string type);

	// show current worn Item
	void printAllItems();
	// get all worn Items;
	map<string, Items*> getListWornItems();

    json itemsToJson();
	void saveItems(string filename);
    // LoggerFile loggerfile;
	std::vector<LoggerObserver *> loggerobservers;
	LoggerFile *loggerfile;
	// Character():loggerfile(nullptr){};
	void setLoggerFile(LoggerFile *loggerfile)
	{
		this->loggerfile = loggerfile;
		registerLogger(loggerfile);
	}

	void registerLogger(LoggerObserver *logger) override
	{
		loggerobservers.push_back(logger);
	}
	void notifyLoggerObserver(const std::string &message) override
	{
		for (LoggerObserver *logobserver : loggerobservers)
		{
			logobserver->update(message);
		}
	}
};
