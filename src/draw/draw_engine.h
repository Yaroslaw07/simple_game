#pragma once
#include "state_buffer/state_buffer.h"


class DrawEngine
{
	StateBuffer* oldState;
protected:
	int screenWidth, screenHight;

public:
	DrawEngine(int sizeX, int sizeY);
	~DrawEngine();

	void update(StateBuffer& newState);
};
