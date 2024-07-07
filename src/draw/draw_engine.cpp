#include "draw_engine.h"

#include "curses.h"
#include "texture_colors.h"


DrawEngine::DrawEngine(int SizeX, int SizeY):
	screenWidth(SizeX),screenHight(SizeY)
{
	oldDraw = new EngineBuffer(SizeX,SizeY);
}

DrawEngine::~DrawEngine() { delete oldDraw; }

void DrawEngine::update(EngineBuffer& NewDraw)
{
	if (NewDraw != *oldDraw)
	{
		for (int Y = 0; Y < NewDraw.getSizeY(); Y++)
		{
			for (int X = 0; X < NewDraw.getSizeX(); X++)
			{

				if (NewDraw.get(X,Y) == oldDraw->get(X,Y))
					continue;
				oldDraw->setObject(X, Y, NewDraw.get(X, Y));
				switch (oldDraw->get(X,Y))
				{
				case 0:
				{
					attron(COLOR_PAIR(Carpet_Pair));
					mvaddch(Y,X,' ');
					attroff(COLOR_PAIR(Carpet_Pair));
					break;
				}
				case 1:
				{
					attron(COLOR_PAIR(Boxes_Pair));
					mvaddch(Y, X, 9604);
					attroff(COLOR_PAIR(Boxes_Pair));
					break;
				}
				case 2:
				{
					attron(COLOR_PAIR(Hero_Pair));
					mvaddch(Y, X, wchar_t(167));
					attroff(COLOR_PAIR(Hero_Pair));
					break;
				}
				case 3:
				{
					attron(COLOR_PAIR(Enemy_Pair));
					mvaddch(Y, X, wchar_t(167));
					attroff(COLOR_PAIR(Enemy_Pair));
					break;
				}
				//Walls
				//╔
				case 4:
				{
					attron(COLOR_PAIR(Wall_Pair));
					mvaddch(Y, X, wchar_t(9556));
					attroff(COLOR_PAIR(Wall_Pair));
					break;
				}
				//╚
				case 5:
				{
					attron(COLOR_PAIR(Wall_Pair));
					mvaddch(Y, X, wchar_t(9562));
					attroff(COLOR_PAIR(Wall_Pair));
					break;
				}
				//╗
				case 6:
				{
					attron(COLOR_PAIR(Wall_Pair));
					mvaddch(Y, X, wchar_t(9559));
					attroff(COLOR_PAIR(Wall_Pair));
					break;
				}
				//╝
				case 7:
				{
					attron(COLOR_PAIR(Wall_Pair));
					mvaddch(Y, X, wchar_t(9565));
					attroff(COLOR_PAIR(Wall_Pair));
					break;
				}
				//═
				case 8:
				{
					attron(COLOR_PAIR(Wall_Pair));
					mvaddch(Y, X, wchar_t(9552));
					attroff(COLOR_PAIR(Wall_Pair));
					break;
				}
				//║
				case 9:
				{
					attron(COLOR_PAIR(Wall_Pair));
					mvaddch(Y, X, wchar_t(9553));
					attroff(COLOR_PAIR(Wall_Pair));
					break;
				}
				case 10:
				{
					attron(COLOR_PAIR(Volt_Pair));
					mvaddch(Y, X, wchar_t(1161));
					attroff(COLOR_PAIR(Volt_Pair));
					break;
				}
				}
			}
		}
	}
	refresh();
}



