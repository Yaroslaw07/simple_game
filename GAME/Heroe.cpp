#include "Heroe.h"

Heroe::Heroe(DrawEngine* de, int x = 1, int y = 1, int lives = 3,char Up_Key='w',char Down_Key = 's',char Left_Key = 'a',char Right_Key = 'd'):Object(de,2, x, y, lives,Route::UP)
{
	this->Up_Key = Up_Key;
	this->Down_Key = Down_Key;
	this->Left_Key = Left_Key;
	this->Right_Key = Right_Key;
}

void Heroe::KeyPress(const char c,Storage& NewDraw)
{
	if (c == Up_Key)
	{
		Move(Route::UP, NewDraw);
	}

	if (c == Down_Key)
	{
		Move(Route::DOWN, NewDraw);
	}

	if (c == Left_Key)
	{
		Move(Route::LEFT, NewDraw);
	}

	if (c == Right_Key)
	{
		Move(Route::RIGHT, NewDraw);
	}
}