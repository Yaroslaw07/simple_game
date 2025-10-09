#pragma once

#include <chrono>
#include <memory>

#include "board/board.h"
#include "draw/draw_engine.h"

class Game
{
	timespec startTime{} ;
	std::unique_ptr<DrawEngine> drawEngine;
	std::unique_ptr<Board> board;
public:
	Game();
	void Start();

protected:
	void gameCycle(const char& key) const;

	static void lose();
	static void win();
};
