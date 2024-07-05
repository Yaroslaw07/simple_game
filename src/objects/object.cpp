#include "Object.h"

Object::Object(int source_index, Coordinate location, int lives = 3,Route route = Route::UP)
{
	indexObject = source_index;

	this->location = location;

	this->lives = lives;

	this->route = route;
}

Object::~Object()
{}

int Object::getX()const
{
	return location.X;
}


int Object::getY()const
{
	return location.Y;
}

Coordinate Object::getLocation()
{
	return location;
}

void Object::eraseLives(const int& damage = 1)
{
	lives -= damage;
}

bool Object::isAlive()const
{
	return (lives > 0);
}

void Object::eraseObject(Storage& source, Coordinate Coord)
{
	source.eraseObject(Coord);
}

void Object::drawObject(Storage& source, Coordinate Coord) const
{
	source.setObject(indexObject,Coord);
}

bool Object::move(const Route A,Storage& NewDraw)
{
	Coordinate coordinate = location + A;
	if (NewDraw.isFreeMove(coordinate) == true)
	{
		NewDraw.eraseObject(location);
		location += A;
		NewDraw.setObject(indexObject, location);
		route = A;
		return true;
	}
	return false;
}

