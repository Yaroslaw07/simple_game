#include "Game.h"
#include <iostream>
#include <fstream>


Game::Game()
{
	LoadLevel("E:\\Step\\C++\\GAME\\GAME\\level.txt");
	Draw_E = new DrawEngine(width, height);
}

void Game::Run()
{

	initscr();
	start_color();
	curs_set(0);
	noecho();
	Turn_on_Colors();

	Draw_E->Update(*Buffer);

	char key = ' ';

	bool isWin = false;

	start_time = std::chrono::steady_clock::now();

	while (key != 'e')
	{
		key = getch();

		if (key != ERR && key != 'e')
		{
			hERO->KeyPress(key,*Buffer,Voltages);
		}

		Evil->EnemyLogic(*Buffer);

		VoltsUpdates();

		Draw_E->Update(*Buffer);

		LoopTime();

		if (hERO->isAlive() == false)
		{
			break;
		}
		else if(Evil->isAlive() == false or !Evil)
		{
			isWin = true;
			break;
		}
	}
	if (isWin == false)
	{
		Lose();
	}
	else
		Win();
	getch();
	endwin();
}


void Game::LoopTime()
{
	std::chrono::duration<double, std::milli> diff = std::chrono::steady_clock::now() - start_time;
	if (diff < std::chrono::duration < double, std::milli>(60))
		return;

	start_time = std::chrono::steady_clock::now();
}

void Game::LoadLevel(const std::string& path)
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
					hERO = new Heroe( C, 3, 'w', 's', 'a', 'd',' ');
					isHero = true;
				}
				else if (index == 3)
				{
					Coordinate C(X, Y);
					Evil = new Enemy(C, 3);
				}
				Buffer->SetObject(X, Y, index);
			}
		}
	}

	in.close();
}


void Game::Lose()
{
	clear();
	attron(COLOR_PAIR(Wall_Pair));
	printw("You Lose");
	attroff(COLOR_PAIR(Wall_Pair));
}

void Game::Win()
{
	clear();
	attron(COLOR_PAIR(Wall_Pair));
	printw("You Win");
	attroff(COLOR_PAIR(Wall_Pair));
}


Game::~Game()
{
	delete Draw_E;
	delete hERO;
}

void Game::VoltsUpdates()
{
	for (auto& elem : Voltages)
	{
		elem.VoltageUpdate(*Buffer);
	}
}