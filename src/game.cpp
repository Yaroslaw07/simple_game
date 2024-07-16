#include "game.h"
#include <fstream>
#include <iostream>

#include "curses.h"
#include "draw/draw_engine.h"

Game::Game()
{
	board = new Board();
	board->loadLevel("level.txt");

	drawEngine = new DrawEngine(board->width, board->height);
}

Game::~Game()
{
	delete drawEngine;
	delete board;
}


void Game::Start()
{
	drawEngine->start(*board->buffer);

	nodelay(stdscr, TRUE);

	char key = '&';

	clock_gettime(CLOCK_MONOTONIC, &startTime);

	while (key != 'e')
	{
		key = getch();

		gameCycle(key);

		timespec sleepTime = {0, 50000000L}; // 50 milliseconds
		nanosleep(&sleepTime, nullptr);

		drawEngine->update(*board->buffer);

		if (board->getState() != NO_STATE)
		{
			break;
		}
	}

	if (board->getState() == NO_HERO)
	{
		lose();
	}
	else if (board->getState() == NO_ENEMIES)
	{
		win();
	}

	nodelay(stdscr, FALSE);
	getch();

	DrawEngine::end();
}

void Game::gameCycle(const char& playerInput) const {

	if (playerInput != ERR && playerInput != 'e')
	{
		board->updateHero(playerInput);
	}

	board->updateEnemy();
	board->updateVoltages();
}

void Game::lose()
{
	clear();
	printw("You lose!");
}

void Game::win()
{
	clear();
	printw("You win!");
}