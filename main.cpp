#include "src/game.h"


int main()
{
	setlocale(LC_ALL, "");

	auto game = Game();
	game.Start();

	return 0;
}
