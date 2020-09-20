#pragma once

#include "Object.h"

class Heroe : public Object
{
private:
	char Up_Key, Down_Key, Left_Key, Right_Key;
public:
	Heroe(DrawEngine* de, int x , int y , int lives,char Up_Key,char Down_Key ,char Left_Key ,char Right_Key );

	void KeyPress(char c,Storage& NewDraw);
};
