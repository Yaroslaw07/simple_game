#pragma once

#include <chrono>
#include <string>

#include "board/storage.h"
#include "draw/draw_engine.h"
#include "objects/enemy/enemy.h"
#include "objects/hero/Heroe.h"

class Game
{
protected:
	std::chrono::steady_clock::time_point start_time;
	Storage* Buffer;
	int width;
	int height;
	Enemy* evil;
	DrawEngine* Draw_E;
	Heroe* hero;
	std::vector<Voltage> Voltages;

public:
	Game();
	void Run();
	~Game();

protected:
	void loopTime();
	void loadLevel(const std::string& path);
	void lose();
	void win();
	void voltsUpdates();
};
