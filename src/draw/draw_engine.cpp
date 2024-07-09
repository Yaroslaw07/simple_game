#include "draw_engine.h"

#include "curses.h"
#include "texture_colors.h"


DrawEngine::DrawEngine(const int& sizeX,const int& sizeY):
	screenWidth(sizeX),screenHight(sizeY)
{
	oldState = new StateBuffer(sizeX, sizeY);
}

DrawEngine::~DrawEngine() { delete oldState; }

void DrawEngine::start(const StateBuffer &initState) const  {
	initscr();
	start_color();
	curs_set(0);
	noecho();

	defineColors();

	for (int y = 0; y < screenHight; y++) {
		for (int x = 0; x < screenWidth; x++) {
			GAME_OBJECTS currObject = initState.get({x, y});
			this->drawPixel({x,y}, currObject);
		}
	}

	refresh();
}

void DrawEngine::update(const StateBuffer& newState) const
{
	for (int y = 0; y < screenHight; y++)
	{
		for (int x = 0; x < screenWidth; x++)
		{
			GAME_OBJECTS currObject = newState.get({x,y});

			if (const GAME_OBJECTS oldObject = oldState->get({x,y});
				currObject != oldObject)
			{
				this->drawPixel({x,y}, currObject);
			}
		}
	}
	refresh();
}

void DrawEngine::end() {
	endwin();
}

void DrawEngine::drawPixel(const Coordinate &coordinate, const GAME_OBJECTS &object) const
{
	const TexturesColors texture = getColorPair(object);
	const wchar_t symbol = getSymbol(object);

	attron(COLOR_PAIR(texture));
	mvaddch(coordinate.y, coordinate.x, symbol);
	attroff(COLOR_PAIR(texture));

	oldState->setObject({coordinate.x, coordinate.y}, object);
}



