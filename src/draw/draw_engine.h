#pragma once


#include "../board/storage.h"

class DrawEngine
{
	Storage* oldDraw;
protected:
	int screenWidth, screenHight;

public:
	DrawEngine();
	DrawEngine(int SizeX, int SizeY);
	~DrawEngine();

	void update(Storage& NewDraw);
};
