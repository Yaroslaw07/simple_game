#pragma once
#include "route_coordinate.h"

class EngineBuffer
{
	int* data;
	int sizeX, sizeY;
public:
	EngineBuffer(int sizeX, int sizeY);
	EngineBuffer(const EngineBuffer& source);

	~EngineBuffer();

	EngineBuffer& operator =(const EngineBuffer& source);
	bool operator !=(const EngineBuffer& source) const;

	int get(int X, int Y) const;
	int getSizeX() const;
	int getSizeY() const;

	bool isFreeMove(Coordinate& point);

	void setObject(int X, int Y, int index);
	void eraseObject(const Coordinate& location);
	void setObject(int index, const Coordinate& location);
};