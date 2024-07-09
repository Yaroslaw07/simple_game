#pragma once

#include "objects/object.h"

class Voltage:public Object
{
	bool isNewVolt = true;
public:
	Voltage(Coordinate location, Route direction): Object(GAME_OBJECTS::VOLT, location, 1, direction)
    {
    };

	bool isNew() const {return isNewVolt;}
	void markAsOld() {isNewVolt = false;}
};