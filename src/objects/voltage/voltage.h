#pragma once

#include <vector>

#include "objects/object.h"
#include "board/engine_buffer.h"

class Voltage:public Object
{
	bool isNewVolt = true;
public:
	Voltage(Coordinate location, Route direction);

	Coordinate voltageUpdate(Storage& NewDraw);

	void deleteVoltage(Storage& NewDraw) const;
};

void createVoltage(std::vector<Voltage>& Volts, Storage& Buff, Coordinate& a, const Route& route);