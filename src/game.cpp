#include "game.h"
#include <fstream>
#include <iostream>

#include "curses.h"
#include "draw/draw_engine.h"

#include "draw/texture_colors.h"

Game::Game()
{
	board = new Board();
	board->loadLevel("level.txt");

	drawEngine = new DrawEngine(board->width, board->height);

	drawEngine->update(*board->buffer);
}

Game::~Game()
{
	delete drawEngine;
	delete board;
}

void Game::gameCycle(const char& playerInput) {

	if (playerInput != ERR && playerInput != 'e')
	{
		board->updateHero(playerInput);
	}

	// board->updateEnemy();
	// board->updateVoltages();
}


void Game::Start()
{
	initscr();
	start_color();
	curs_set(0);
	noecho();

	nodelay(stdscr, TRUE);

	defineColors();


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
	endwin();
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