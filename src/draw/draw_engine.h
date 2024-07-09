#pragma once
#include "state_buffer/state_buffer.h"


class DrawEngine
{
	StateBuffer* oldState;
	int screenWidth, screenHight;
public:
	DrawEngine(const int& sizeX,const int& sizeY);
	~DrawEngine();

	void start(const StateBuffer& initState) const;
	void update(const StateBuffer& newState) const;
	static void end() ;
protected:
	void drawPixel(const Coordinate& coordinate, const GAME_OBJECTS &object) const;
};
