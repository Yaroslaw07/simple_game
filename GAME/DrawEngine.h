#pragma once
#include <vector>
#include "Colors_of_Textures.h"
#include "Storage.h"

class DrawEngine
{
	Storage* OldDraw;
protected:
	int Screen_Width, Screen_Hight;

public:
	DrawEngine();
	DrawEngine(int SizeX, int SizeY);
	~DrawEngine();

	void Update(Storage& NewDraw);
};