#include <iostream>
#include <Window.h>

using namespace Rekd2D::Core;

int main(int argc, char *argv[])
{
	Window* window = new Window("Test Window", 800, 600);
	window->Show();
	Event e;
	while (window->Update(&e))
	{
		
	}
	window->Dispose();
	delete window;
	return 0;
}