#pragma once
#include "Object.h"
class Voltage:public Object
{
public:
	Voltage(DrawEngine* de, int x, int y, Route direction);
};

