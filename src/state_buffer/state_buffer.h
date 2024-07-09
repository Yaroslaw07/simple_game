#pragma once
#include "../route_coordinate/route_coordinate.h"
#include "../objects/object_map.h"

class StateBuffer
{
	int** data;
	int sizeX, sizeY;

	void setObject(const int& X,const int& Y,const GAME_OBJECTS& object);
public:
	StateBuffer(int sizeX, int sizeY);
	StateBuffer(const StateBuffer& source);

	~StateBuffer();

	StateBuffer& operator =(const StateBuffer& source);
	bool operator !=(const StateBuffer& source) const;

	GAME_OBJECTS get(const Coordinate& coordinate) const;
	int getSizeX() const;
	int getSizeY() const;

	void eraseObject(const Coordinate& location);
	void setObject(const Coordinate& location, const GAME_OBJECTS& object);
};