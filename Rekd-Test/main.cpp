#include <iostream>
#include <Rekd2D.h>

using namespace Rekd2D::Core;

int main(int argc, char *argv[])
{
	Rekd::InitGL(1, 2);
	Window* window = new Window("Test Window", 800, 480);
	window->Show();
	Event e;
	while (window->Update(&e))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glRotatef(1, 0, 0, 1);
		//glTranslatef(1, 0, 0);
		glColor3f(1.0f, 0, 0);
		glBegin(GL_QUADS);
			glVertex2f(-100, -100);
			glVertex2f(100, -100);
			glVertex2f(100, 100);
			glVertex2f(-100, 100);
		glEnd();
	}
	window->Dispose();
	delete window;
	return 0;
}