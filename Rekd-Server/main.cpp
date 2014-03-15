#include "Game1.h"

int main(int argc, char *argv[])
{
	Game1* game = new Game1();
	game->Run("Test Server", 800, 480);
	delete game;
	return 0;
}