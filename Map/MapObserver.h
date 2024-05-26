#pragma once

#include "Map.h"
//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class Map;
class MapObserver {
public:
	/// <summary>
	/// MapObserver constructor
	/// </summary>
	MapObserver();
	/// <summary>
	/// When the value of map change, redisplay map
	/// </summary>
	/// <param name="mapS"></param>
	virtual void Update(Map* mapS);

}; 

