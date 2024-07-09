#pragma once
#include "state_buffer/state_buffer.h"


class DrawEngine
{
	StateBuffer* oldState;
	int screenWidth, screenHight;

	bool isFirstUpdate;
public:
	DrawEngine(const int& sizeX,const int& sizeY);
	~DrawEngine();

	void update(const StateBuffer& newState);
};
