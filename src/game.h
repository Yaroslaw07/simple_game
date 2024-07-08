#pragma once

#include <chrono>

#include "board/board.h"
#include "draw/draw_engine.h"

class Game
{
	timespec startTime{};
	DrawEngine* drawEngine;
	Board* board;
public:
	Game();
	void Start();
	~Game();

protected:
	void gameCycle(const char& key);

	static void lose();
	static void win();
};
