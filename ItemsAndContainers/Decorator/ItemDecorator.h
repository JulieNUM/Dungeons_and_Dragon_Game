#pragma once
#include "../../Character/AbstractCharacter.h"
class ItemDecorator : public AbstractCharacter //inherit
{
protected: 
	AbstractCharacter* baseCharacter;
	map<string, Items*> listWornItems; 

public:
	// ItemDecorator(AbstractCharacter* baseCharacter);
	/// Add a new item to container
	/// @return void
	virtual void addItem(Items* items, string type)=0;

	/// Remove Item from container
	/// @return void
	virtual void removeItem(string type)=0;
	virtual map<string, Items*> getListWornItems() =0;
};