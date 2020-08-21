#include "Game.h"
#include <conio.h>
#include <iostream>


bool Game::Game_Process()
{
	char key = ' ';

	start_time = std::chrono::steady_clock::now();

	while (key != 'e')
	{
		
		while (!GetComand(&key))
		{
			Loop();
		}
	}

	return true;
}

bool Game::GetComand(char* c)
{
	if (_kbhit())
	{
		*c = _getch();
		return true;
	}

	return false;
}


void Game::Loop()
{
	std::chrono::duration<double, std::milli> diff = std::chrono::steady_clock::now() - start_time;
	if (diff < std::chrono::duration < double, std::milli>(33.3))
		return;

	start_time = std::chrono::steady_clock::now();
}