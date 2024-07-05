#include "Voltage.h"


Voltage::Voltage(Coordinate location, Route direction):Object(10,location,1,direction)
{}

Coordinate Voltage::voltageUpdate(Storage& NewDraw)
{
	if (isNewVolt == true)
	{
		isNewVolt = false;
	}
	else if (move(route, NewDraw))
	{
		return {-1,-1};
	}
	else
	{
		this->eraseLives(-1);
		deleteVoltage(NewDraw);
		return location + route;
	}
	return {-1, -1};
}

void Voltage::deleteVoltage(Storage& NewDraw) const
{
	NewDraw.eraseObject(location);
}

void createVoltage(std::vector<Voltage>& Volts, Storage& Buff, Coordinate& a, const Route& route)
{
	if (Coordinate check = a + route; Buff.isFreeMove(check) == true)
	{
		Volts.emplace_back(check,route);
		Buff.setObject(10, check);
	}
}

