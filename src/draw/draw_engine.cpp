#include "draw_engine.h"

#include "curses.h"
#include "texture_colors.h"


DrawEngine::DrawEngine(const int& sizeX,const int& sizeY):
	screenWidth(sizeX),screenHight(sizeY)
{
	oldState = nullptr;
}

DrawEngine::~DrawEngine() { delete oldState; }

void DrawEngine::update(const StateBuffer& newState)
{
	if (oldState == nullptr)
	{
		oldState = new StateBuffer(newState);
		return;
	}

	for (int y = 0; y < newState.getSizeY(); y++)
	{
		for (int x = 0; x < newState.getSizeX(); x++)
		{

			if (newState.get({x,y}) == oldState->get({x,y}))
				continue;

			GAME_OBJECTS currObject = GAME_OBJECTS(newState.get({x,y}));
			oldState->setObject({x, y}, currObject);

			TexturesColors texture = getColorPair(currObject);
			wchar_t symbol = getSymbol(currObject);

			attron(texture);
			mvaddch(y, x, symbol);
			attroff(texture);
		}
	}

	refresh();
}



