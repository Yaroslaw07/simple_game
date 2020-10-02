#pragma once
#include "Voltage.h"

class Enemy :public Object
{
public:
	Enemy(Coordinate location, int lives);

	void EnemyLogic(Storage& NewDraw);
};