#include "Game.h"

void Rekd2D::Core::Game::Run(char* title, unsigned int width, unsigned int height)
{
	Rekd::InitGL(1, 2);
	Init();
	m_Window = new Window(title, width, height);
	m_Renderer = new Renderer(m_Window);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	Load();
	Event e;
	m_Window->Show();
	while (m_Window->Update(&e))
	{
		Update();
		Render();
	}
	Unload();
	m_Renderer->Dispose();
	m_Window->Dispose();
	delete m_Window;
	delete m_Renderer;
}