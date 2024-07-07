#pragma once
#include "objects/object.h"

class Enemy :public Object
{
public:
	Enemy(Coordinate location, int lives);

	void EnemyLogic(EngineBuffer& NewDraw);
};