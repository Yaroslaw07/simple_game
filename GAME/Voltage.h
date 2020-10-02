#pragma once
#include "Object.h"
class Voltage:public Object
{
	bool isNewVolt = true;
public:
	Voltage(Coordinate location, Route direction);

	Coordinate VoltageUpdate(Storage& NewDraw);

	void DeleteVoltage(Storage& NewDraw);
};

void CreateVoltage(std::vector<Voltage>& Volts, Storage& Buff, Coordinate& a, const Route& route);