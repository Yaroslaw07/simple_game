#include "Heroe.h"

Heroe::Heroe(Coordinate location, int lives = 3,char Up_Key='w',char Down_Key = 's',char Left_Key = 'a',char Right_Key = 'd',char Shoot_Key = ' '):Object(2, location, lives,Route::UP)
{
	this->Up_Key = Up_Key;
	this->Down_Key = Down_Key;
	this->Left_Key = Left_Key;
	this->Right_Key = Right_Key;
	this->Shoot_Key = Shoot_Key;
}

void Heroe::KeyPress(const char c,Storage& NewDraw, std::vector<Voltage>& Voltages)
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

	if (c == Shoot_Key)
	{
		CreateVoltage(Voltages, NewDraw, location, route);
	}
}