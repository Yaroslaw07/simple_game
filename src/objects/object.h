#pragma once
#include "board/route_coordinate.h"
#include "board/engine_buffer.h"

class Object
{
protected:
	int lives;
	Coordinate location;

	int indexObject;
	Route route;

public:
	Object(int source_index,Coordinate location, int lives,Route route);
	~Object();

	int getX() const;
	int getY() const;

	Coordinate getLocation();

	void eraseLives(const int& damage);
	bool isAlive() const;

	static void eraseObject(EngineBuffer& source, Coordinate Coord);
	void drawObject(EngineBuffer& source, Coordinate Coord) const;

	bool move(Route A, EngineBuffer& NewDraw);
};