#pragma once
#include "Route+Coordinate.h"

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
	void Set(int X, int Y, int index);
	int Get(int X, int Y) const;
	int GetSizeX() const;
	int GetSizeY() const;

	bool isFreeMove(Coordinate& point);
};