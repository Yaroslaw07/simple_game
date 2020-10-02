#include "Voltage.h"

Voltage::Voltage(Coordinate location, Route direction):Object(10,location,1,direction)
{}

Coordinate Voltage::VoltageUpdate(Storage& NewDraw)
{
	if (isNewVolt == true)
	{
		isNewVolt = false;
	}
	else if (Object::Move(route, NewDraw))
	{
		return Coordinate(-1,-1);
	}
	else
	{
		this->eraseLives(-1);
		DeleteVoltage(NewDraw);
		return location + route;
	}
	return Coordinate(-1, -1);
}

void Voltage::DeleteVoltage(Storage& NewDraw)
{
	NewDraw.EraseObject(location);
}

void CreateVoltage(std::vector<Voltage>& Volts, Storage& Buff, Coordinate& a, const Route& route)
{
	Coordinate Check = a + route;
	if (Buff.isFreeMove(Check) == true)
	{
		Volts.push_back(Voltage(Check,route));
		Buff.SetObject(10, Check);
	}
}

