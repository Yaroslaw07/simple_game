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

	// bool isWin = false;

	clock_gettime(CLOCK_MONOTONIC, &startTime);

	while (key != 'e')
	{
		key = getch();

		gameCycle(key);

		timespec sleepTime = {0, 50000000L}; // 50 milliseconds
		nanosleep(&sleepTime, nullptr);

		drawEngine->update(*board->buffer);
	}

	// isWin ? win() : lose();

	getch();

	drawEngine->end();
}

void Game::gameCycle(const char& playerInput) {

	if (playerInput != ERR && playerInput != 'e')
	{
		board->updateHero(playerInput);
	}

	board->updateEnemy();
	// boared->updateVoltages();
}

// void Game::lose()
// {
// 	clear();
// 	attron(Wall_Pair);
// 	printw("You Lose");
// 	attroff(Wall_Pair);
// }
//
// void Game::win()
// {
// 	clear();
// 	attron(Wall_Pair);
// 	printw("You Win");
// 	attroff(Wall_Pair);
// }