#pragma once

#include <vector>

#include "../object.h"

#include "../../board/storage.h"

class Voltage:public Object
{
	bool isNewVolt = true;
public:
	Voltage(Coordinate location, Route direction);

	Coordinate voltageUpdate(Storage& NewDraw);

	void deleteVoltage(Storage& NewDraw) const;
};

void createVoltage(std::vector<Voltage>& Volts, Storage& Buff, Coordinate& a, const Route& route);