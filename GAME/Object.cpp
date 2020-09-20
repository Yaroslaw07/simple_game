#include "Object.h"

Object::Object(DrawEngine* de, int source_index, int x = 1, int y = 1, int lives = 3,Route route = Route::UP)
{
	draw_engine = de;
	IndexObject = source_index;

	location.X = x;
	location.Y = y;

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
	draw_engine->Erase(source,Coord);
}


void Object::drawObject(Storage& source, Coordinate Coord)
{
	draw_engine->Draw(source, IndexObject,Coord);
}

bool Object::Move(const Route A,Storage& NewDraw)
{
	Coordinate C = location + A;
	if (NewDraw.isFreeMove(C) == true)
	{
		draw_engine->Erase(NewDraw, location);
		location += A;
		draw_engine->Draw(NewDraw, IndexObject, location);
		route = A;
		return true;
	}
	return false;
}

