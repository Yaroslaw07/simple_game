#pragma once

#include <chrono>
#include <string>
#include <vector>
#include "Heroe.h"
#include "Enemy.h"

class Game
{
protected:
	std::chrono::steady_clock::time_point start_time;
	DrawEngine Draw_Engine;
	Storage Buffer;
	int width;
	int height;
	Enemy* Evil;
	DrawEngine* Draw_E;
	Heroe* hERO;


public:
	Game();
	void Run();
	~Game();

protected:
	void LoopTime();
	void LoadLevel(const std::string& path);
	void Lose();
	void Win();
};