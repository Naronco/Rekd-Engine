#include "Pong.h"

int main(int argc, char *argv[])
{
	Pong* game = new Pong();
	game->Run("InsanityPong", 800, 480);
	delete game;
	return 0;
}