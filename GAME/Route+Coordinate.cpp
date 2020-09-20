#include "Route+Coordinate.h"

Coordinate::Coordinate():
	X(0), Y(0){}

Coordinate::Coordinate(int X, int Y) :
	X(X), Y(Y){}

void Coordinate::operator+=(const Route& Route_Path)
{
	switch (Route_Path)
	{
	case Route::UP:
		this->Y--;
		break;
	case Route::DOWN:
		this->Y++;
		break;
	case Route::LEFT:
		this->X--;
		break;
	case Route::RIGHT:
		this->X++;
		break;
	}

}

const Coordinate operator+(const Coordinate& current, const Route& Route_Path)
{
	Coordinate location = current;

	switch (Route_Path)
	{
	case Route::UP:
		location.Y--;
		break;
	case Route::DOWN:
		location.Y++;
		break;
	case Route::LEFT:
		location.X--;
		break;
	case Route::RIGHT:
		location.X++;
		break;
	}

	return location;
}