#include "Object.h"

Object::Object(int source_index, Coordinate location, int lives = 3,Route route = Route::UP)
{
	IndexObject = source_index;

	this->location = location;

	Lives = lives;

	this->route = route;
}


Object::~Object()
{}

int Object::GetX()const
{
	return location.X;
}


int Object::GetY()const
{
	return location.Y;
}

Coordinate Object::GetLocation()
{
	return location;
}

void Object::eraseLives(const int& damage = 1)
{
	Lives -= damage;
}

bool Object::isAlive()const
{
	return (Lives > 0);
}

void Object::eraseObject(Storage& source, Coordinate Coord)
{
	source.EraseObject(Coord);
}

void Object::drawObject(Storage& source, Coordinate Coord)
{
	source.SetObject(IndexObject,Coord);
}

bool Object::Move(const Route A,Storage& NewDraw)
{
	Coordinate C = location + A;
	if (NewDraw.isFreeMove(C) == true)
	{
		NewDraw.EraseObject(location);
		location += A;
		NewDraw.SetObject(IndexObject, location);
		route = A;
		return true;
	}
	return false;
}

