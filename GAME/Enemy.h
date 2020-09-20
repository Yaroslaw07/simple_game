#pragma once
#include "Object.h"

class Enemy :public Object
{
public:
	Enemy(DrawEngine* de, int x, int y, int lives);

	void EnemyLogic(Storage& NewDraw);
};