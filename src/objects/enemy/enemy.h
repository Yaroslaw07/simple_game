#pragma once
#include "../object.h"

class Enemy :public Object
{
public:
	Enemy(Coordinate location, int lives);

	void EnemyLogic(Storage& NewDraw);
};