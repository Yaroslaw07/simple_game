#pragma once

#include <chrono>

class Game
{
protected:
	std::chrono::steady_clock::time_point start_time;
public:
	bool Game_Process();
protected:
	bool GetComand(char* c);
	void Loop();
};