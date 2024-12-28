
#include <iostream>
#include "Game.h"

int main()
{
	Game game;

	game.start();

	game.print_board();

	game.step(Coord('H', 1), Coord('H', 5));

	game.print_board();

	game.step(Coord('H', 5), Coord('E', 5));
	//game.step(Coord('A', 8), Coord('A', 1));

	game.print_board();
}

