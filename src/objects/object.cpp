#include "object.h"

Object::Object(const GAME_OBJECTS& object, Coordinate location, int lives,Route route):
	lives(lives),
	route(route),
	location(location),
	objectType(object)
{
}

Coordinate Object::getLocation() const
{
	return location;
}

void Object::setLocation(const Coordinate &newCoordinate) {
	location = newCoordinate;
}

Route Object::getRoute() const
{
	return route;
}

void Object::eraseLives(const int& damage)
{
	lives -= damage;
}

bool Object::isAlive()const
{
	return (lives > 0);
}

GAME_OBJECTS Object::getObjectType() const {
	return objectType;
}
