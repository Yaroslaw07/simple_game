#pragma once

#include <chrono>
#include <string>
#include "Heroe.h"
#include "Enemy.h"

class Game
{
protected:
	std::chrono::steady_clock::time_point start_time;
	Storage* Buffer;
	int width;
	int height;
	Enemy* Evil;
	DrawEngine* Draw_E;
	Heroe* hERO;
	std::vector<Voltage> Voltages;

public:
	Game();
	void Run();
	~Game();

protected:
	void LoopTime();
	void LoadLevel(const std::string& path);
	void Lose();
	void Win();
	void VoltsUpdates();
};