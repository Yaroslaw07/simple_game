#include "draw_engine.h"

#include "curses.h"
#include "texture_colors.h"


DrawEngine::DrawEngine(const int& sizeX,const int& sizeY):
	screenWidth(sizeX),screenHight(sizeY)
{
	oldState = new StateBuffer(sizeX, sizeY);
	isFirstUpdate = true;
}

DrawEngine::~DrawEngine() { delete oldState; }

void DrawEngine::update(const StateBuffer& newState)
{
	for (int y = 0; y < screenHight; y++)
	{
		for (int x = 0; x < screenWidth; x++)
		{
			GAME_OBJECTS currObject = newState.get({x,y});

			TexturesColors texture = getColorPair(currObject);
			wchar_t symbol = getSymbol(currObject);

			attron(COLOR_PAIR(texture));
			mvaddch(y, x, symbol);
			attroff(COLOR_PAIR(texture));

			oldState->setObject({x, y}, currObject);
		}
	}

	isFirstUpdate = false;
	refresh();
}



