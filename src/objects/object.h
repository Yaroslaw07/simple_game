#pragma once
#include "object_map.h"
#include "route_coordinate/route_coordinate.h"

class Object
{
protected:
	int lives;

	Route route;
	Coordinate location;

	GAME_OBJECTS objectType;

public:
	Object(const GAME_OBJECTS& object, Coordinate location, int lives = 3,Route route = Route::UP);

	Coordinate getLocation() const;
	void setLocation(const Coordinate& newCoordinate);

	Route getRoute() const;

	void eraseLives(const int& damage);
	bool isAlive() const;

	GAME_OBJECTS getObjectType() const;
};