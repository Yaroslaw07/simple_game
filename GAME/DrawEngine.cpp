#include "DrawEngine.h"
#include <iostream>

DrawEngine::DrawEngine() :
	DrawEngine(40,20){}

DrawEngine::DrawEngine(int SizeX, int SizeY):
	Screen_Width(SizeX),Screen_Hight(SizeY){}

DrawEngine::~DrawEngine(){}

void DrawEngine::Erase(Storage& source, const Coordinate& location)
{
	source.Set(location.X, location.Y, 0);
}

void DrawEngine::Draw(Storage& source, int index, const Coordinate& location)
{
	source.Set(location.X, location.Y,index);
}

void DrawEngine::Update(Storage& NewDraw)
{
	if (NewDraw != OldDraw)
	{
		for (int Y = 0; Y < NewDraw.GetSizeY(); Y++)
		{
			for (int X = 0; X < NewDraw.GetSizeX(); X++)
			{

				if (NewDraw.Get(X,Y) == OldDraw.Get(X,Y))
					continue;
				OldDraw.Set(X, Y, NewDraw.Get(X, Y));
				switch (OldDraw.Get(X,Y))
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
					mvaddch(Y, X, wchar_t(9604));
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
				refresh();
				}
			}
		}
	}
	refresh();
}



