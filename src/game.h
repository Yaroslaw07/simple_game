#pragma once

#include <string>
#include <ctime>
#include <chrono>

#include "board/engine_buffer.h"
#include "draw/draw_engine.h"
#include "objects/enemy/enemy.h"
#include "objects/hero/hero.h"

class Game
{
	timespec startTime;

	EngineBuffer* buffer;
	DrawEngine* drawEngine;

	int width;
	int height;

	Heroe* hero;
	Enemy* evil;
	std::vector<Voltage> voltages;

public:
	Game();
	void Run();
	~Game();

protected:
	Coordinate loadLevel(const std::string& path);

	void lose();
	void win();

	void voltsUpdates();
};
