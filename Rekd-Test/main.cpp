#include "Game1.h"

int main(int argc, char *argv[])
{
	Game1* game = new Game1();
	game->Run("Test Window", 800, 480, 1280, 1024);
	delete game;
	return 0;
}