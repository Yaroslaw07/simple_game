#include "draw_engine.h"

#include "curses.h"
#include "texture_colors.h"


DrawEngine::DrawEngine(int sizeX, int sizeY):
	screenWidth(sizeX),screenHight(sizeY)
{
	oldState = new StateBuffer(sizeX,sizeY);
}

DrawEngine::~DrawEngine() { delete oldState; }

void DrawEngine::update(StateBuffer& newState)
{
	if (newState != *oldState)
	{
		for (int Y = 0; Y < newState.getSizeY(); Y++)
		{
			for (int X = 0; X < newState.getSizeX(); X++)
			{

				if (newState.get({X,Y}) == oldState->get({X,Y}))
					continue;

				GAME_OBJECTS currObject = GAME_OBJECTS(newState.get({X,Y}));
				oldState->setObject({X, Y}, currObject);

				TexturesColors texture = getColorPair(currObject);
				wchar_t symbol = getSymbol(currObject);

				attron(texture);
				mvaddch(Y, X, symbol);
				attroff(texture);
			}
		}
	}

	refresh();
}



