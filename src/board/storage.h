#pragma once
#include "route_coordinate.h"

class Storage
{
	int* Data;
	int SizeX, SizeY;
public:
	Storage();
	Storage(int sizeX, int sizeY);
	Storage(const Storage& source);
	~Storage();

	void operator =(const Storage& source);
	bool operator !=(const Storage& source);
	int get(int X, int Y) const;
	int getSizeX() const;
	int getSizeY() const;

	bool isFreeMove(Coordinate& point);

	void setObject(int X, int Y, int index);
	void eraseObject(const Coordinate& location);
	void setObject(int index, const Coordinate& location);
};