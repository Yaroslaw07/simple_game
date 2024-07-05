#pragma once

enum class Route
{
	UP,DOWN,LEFT,RIGHT
};

class Coordinate
{
public:
	int X, Y;
	Coordinate();
	Coordinate(int X, int Y);
	friend const Coordinate operator+(const Coordinate& current, const Route& Route_Path);
	void operator+=(const Route& Route_Path);
};