#pragma once
#include "Colors_of_Textures.h"
#include "Storage.h"

class DrawEngine
{
	Storage OldDraw;
protected:
	int Screen_Width, Screen_Hight;

public:
	DrawEngine();
	DrawEngine(int SizeX, int SizeY);
	~DrawEngine();

	void Erase(Storage& source, const Coordinate& location);
	void Draw(Storage& source,int index, const Coordinate& location);

	void Update(Storage& NewDraw);
};