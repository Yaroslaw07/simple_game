#include "Game.h"
#include <fstream>

#include "curses.h"
#include "draw/draw_engine.h"

#include "draw/texture_colors.h"

Game::Game()
{
	loadLevel("");
	Draw_E = new DrawEngine(width, height);
}

void Game::Run()
{
	initscr();
	start_color();
	curs_set(0);
	noecho();

	defineColors();

	Draw_E->update(*Buffer);

	char key = ' ';

	bool isWin = false;

	start_time = std::chrono::steady_clock::now();

	while (key != 'e')
	{
		key = getch();

		if (key != ERR && key != 'e')
		{
			hero->keyPress(key,*Buffer,Voltages);
		}

		evil->EnemyLogic(*Buffer);

		voltsUpdates();

		Draw_E->update(*Buffer);

		loopTime();

		if (hero->isAlive() == false)
		{
			break;
		}
		else if(evil->isAlive() == false or !evil)
		{
			isWin = true;
			break;
		}
	}
	if (isWin == false)
	{
		lose();
	}
	else
		win();
	getch();
	endwin();
}


void Game::loopTime()
{
	std::chrono::duration<double, std::milli> diff = std::chrono::steady_clock::now() - start_time;
	if (diff < std::chrono::duration < double, std::milli>(60))
		return;

	start_time = std::chrono::steady_clock::now();
}

void Game::loadLevel(const std::string& path)
{
	std::ifstream in(path);
	int index;
	bool isHero = false;

	if (in.is_open())
	{
		in >> index;
		width = index;
		in >> index;
		height = index;
		Buffer = new Storage(width,height);

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
					Coordinate C(X, Y);
					hero = new Heroe( C, 3, 'w', 's', 'a', 'd',' ');
					isHero = true;
				}
				else if (index == 3)
				{
					Coordinate C(X, Y);
					evil = new Enemy(C, 3);
				}
				Buffer->setObject(X, Y, index);
			}
		}
	}

	in.close();
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
	delete Draw_E;
	delete hero;
}

void Game::voltsUpdates()
{
	for (auto& elem : Voltages)
	{
		elem.voltageUpdate(*Buffer);
	}
}