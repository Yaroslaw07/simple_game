#pragma once


#include "board/engine_buffer.h"

class DrawEngine
{
	EngineBuffer* oldDraw;
protected:
	int screenWidth, screenHight;

public:
	DrawEngine(int SizeX, int SizeY);
	~DrawEngine();

	void update(EngineBuffer& NewDraw);
};
