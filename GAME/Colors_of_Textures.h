#pragma once

#include "curses.h"

enum TexturesColors
{
	None,
	Carpet_Pair,
	Boxes_Pair,
	Hero_Pair,
	Enemy_Pair,
	Wall_Pair,
	Volt_Pair
};



inline void Turn_on_Colors()
{
	init_pair(Carpet_Pair, COLOR_GREEN, COLOR_RED | 8);
	init_pair(Boxes_Pair, COLOR_CYAN, COLOR_CYAN | 8);
	init_pair(Hero_Pair, COLOR_WHITE, COLOR_RED | 8);
	init_pair(Enemy_Pair, COLOR_BLACK, COLOR_RED | 8);
	init_pair(Wall_Pair, COLOR_RED, COLOR_YELLOW);
	init_pair(Volt_Pair, COLOR_CYAN, COLOR_RED | 8);
}