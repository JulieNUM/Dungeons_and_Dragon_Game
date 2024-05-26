#include "MapObserver.h"

MapObserver::MapObserver()
{
}


void MapObserver::Update(Map* mapS) {
	mapS->printMap();
}