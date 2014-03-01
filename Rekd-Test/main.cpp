#include <iostream>
#include <Rekd2D.h>

using namespace Rekd2D::Core;

int main(int argc, char *argv[])
{
	Rekd::InitGL(1, 2);
	Window* window = new Window("Test Window", 800, 480);
	window->Show();
	Event e;
	Renderer* renderer = new Renderer(window);
	while (window->Update(&e))
	{
		renderer->Begin();
		renderer->DrawRect(10, 10, 80, 80);
		renderer->End();
	}
	window->Dispose();
	delete window;
	return 0;
}