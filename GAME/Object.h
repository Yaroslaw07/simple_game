#pragma once
#include "DrawEngine.h"

class Object
{
protected:
	int Lives;
	Coordinate location;
	DrawEngine* draw_engine;
	int IndexObject;
	Route route;

public:
	Object(DrawEngine* de, int source_index, int x , int y , int lives,Route route);
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