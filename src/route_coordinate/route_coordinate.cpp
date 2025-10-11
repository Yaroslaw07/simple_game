#include "route_coordinate.h"
#include <cmath>

Coordinate::Coordinate():
	x(0), y(0){}

Coordinate::Coordinate(int x, int y) :
	x(x), y(y){}

double Coordinate::distance(const Coordinate& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

void Coordinate::operator+=(const Route& route)
{
	switch (route)
	{
	case Route::UP:
		this->y--;
		break;
	case Route::DOWN:
		this->y++;
		break;
	case Route::LEFT:
		this->x--;
		break;
	case Route::RIGHT:
		this->x++;
		break;
	}

}

bool Coordinate::operator==(const Coordinate &coordinate) const {
	return (this->x == coordinate.x && this->y == coordinate.y);
}

bool Coordinate::operator!=(const Coordinate& coordinate) const {
    return !(*this == coordinate);
}

Coordinate operator+(const Coordinate& current, const Route& route)
{
	Coordinate location = current;

	switch (route)
	{
	case Route::UP:
		location.y--;
		break;
	case Route::DOWN:
		location.y++;
		break;
	case Route::LEFT:
		location.x--;
		break;
	case Route::RIGHT:
		location.x++;
		break;
	}

	return location;
}

Coordinate operator+(const Coordinate& a, const Coordinate& b) {
    return Coordinate(a.x + b.x, a.y + b.y);
}
