#include <iostream>
#include <Window.h>

using namespace Rekd2D::Core;

int main(int argc, char *argv[])
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	Window* window = new Window("Test Window", 800, 600);
	window->Show();
	Event e;
	while (window->Running)
	{
		window->Update(&e);
	}
	window->Dispose();
	delete window;
	return 0;
}