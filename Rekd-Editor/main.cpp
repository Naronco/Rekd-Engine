#include "MainWindow.h"

int main(int argc, char *argv[])
{
	MainWindow* game = new MainWindow();
	game->Run("Test Window", 800, 480);
	delete game;
	return 0;
}