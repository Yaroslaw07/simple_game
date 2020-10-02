#pragma once
#include "DrawEngine.h"

class Object
{
protected:
	int Lives;
	Coordinate location;
	int IndexObject;
	Route route;

public:
	Object(int source_index,Coordinate location, int lives,Route route);
	~Object();

	int GetX() const;
	int GetY() const;

	Coordinate GetLocation();

	void eraseLives(const int& damage);
	bool isAlive() const;

	void eraseObject(Storage& source, Coordinate Coord);
	void drawObject(Storage& source, Coordinate Coord);

	bool Move(const Route A, Storage& NewDraw);
};