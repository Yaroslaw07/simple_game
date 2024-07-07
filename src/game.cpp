#include "game.h"
#include <fstream>

#include "curses.h"
#include "draw/draw_engine.h"

#include "draw/texture_colors.h"

Game::Game()
{
	const Coordinate size = loadLevel("level.txt");

	width = size.X;
	height = size.Y;

	drawEngine = new DrawEngine(width, height);
}

void Game::Run()
{
	initscr();
	start_color();
	curs_set(0);
	noecho();

	nodelay(stdscr, TRUE);

	defineColors();

	drawEngine->update(*buffer);

	char key = ' ';

	bool isWin = false;

	clock_gettime(CLOCK_MONOTONIC, &startTime);

	while (key != 'e')
	{
		key = getch();

		if (key != ERR && key != 'e')
		{
			hero->keyPress(key,*buffer,voltages);
		}

		evil->EnemyLogic(*buffer);

		voltsUpdates();

		drawEngine->update(*buffer);

		if (hero->isAlive() == false)
		{
			break;
		}

		if(evil && evil->isAlive() == false or !evil)
		{
			isWin = true;
			break;
		}

		timespec sleepTime = {0, 50000000L}; // 50 milliseconds
		nanosleep(&sleepTime, NULL);
	}

	isWin ? win() : lose();

	getch();
	endwin();
}

Coordinate Game::loadLevel(const std::string& path)
{
	std::ifstream in(path);
	int width;
	int height;

	if (in.is_open()) {
		int index;
		bool isHero = false;

		in >> index;
		width = index;
		in >> index;
		height = index;

		buffer = new EngineBuffer(width,height);

		for (int Y = 0; Y < height; Y++)
		{
			for (int X = 0; X < width; X++)
			{
				in >> index;
				if ((index == 2 and isHero == true) or index == 10)
				{
					index = 0;
				}
				else if(index == 2)
				{
					const Coordinate C(X, Y);
					hero = new Heroe( C, 3, 'w', 's', 'a', 'd',' ');
					isHero = true;
				}
				else if (index == 3)
				{
					Coordinate C(X, Y);
					evil = new Enemy(C, 3);
				}
				buffer->setObject(X, Y, index);
			}
		}
	} else {
		printw("Error: Unable to open level file.");
		getch(); // Wait for user input to acknowledge the error.
		endwin(); // Restore terminal to its original state.
		exit(EXIT_FAILURE); // Exit the program with an error code.
	}
	in.close();

	return {width, height};
}

void Game::lose()
{
	clear();
	attron(COLOR_PAIR(Wall_Pair));
	printw("You Lose");
	attroff(COLOR_PAIR(Wall_Pair));
}

void Game::win()
{
	clear();
	attron(COLOR_PAIR(Wall_Pair));
	printw("You Win");
	attroff(COLOR_PAIR(Wall_Pair));
}


Game::~Game()
{
	delete drawEngine;
	delete hero;
}

void Game::voltsUpdates()
{
	for (auto& elem : voltages)
	{
		elem.voltageUpdate(*buffer);
	}
}