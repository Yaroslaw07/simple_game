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

	double distance(const Coordinate& other) const;

	friend Coordinate operator+(const Coordinate& current, const Route& route);
	friend Coordinate operator+(const Coordinate& a, const Coordinate& b);
	void operator+=(const Route& route);
	bool operator==(const Coordinate& coordinate) const;
	bool operator!=(const Coordinate& coordinate) const;
};