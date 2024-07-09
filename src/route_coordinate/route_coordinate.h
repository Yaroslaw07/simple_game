#pragma once

enum class Route
{
	UP,DOWN,LEFT,RIGHT
};

class Coordinate
{
public:
	int x, y;
	Coordinate();
	Coordinate(int x, int y);

	friend Coordinate operator+(const Coordinate& current, const Route& route);
	void operator+=(const Route& route);
	bool operator==(const Coordinate& coordinate) const;
};