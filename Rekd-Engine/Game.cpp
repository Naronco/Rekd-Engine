#include "Game.h"

void Rekd2D::Core::Game::Run(char* title, unsigned int width, unsigned int height)
{
	Rekd::InitGL(3, 1);
	Init();
	m_Window = new Window(title, width, height);
	m_Renderer = new Renderer(m_Window);
	glEnable(GL_TEXTURE_2D);
	Load();
	Event e;
	m_Window->Show();
	while (m_Window->Update(&e))
	{
		if (e.Type == Enum::EventType::MouseMove)
		{
			MouseState s = Mouse::GetState();
			s.X = (int)((e.MouseMove.DestinationX + e.MouseMove.RelativeX) / (float)m_Window->GetWidth() * width);
			s.Y = (int)((e.MouseMove.DestinationY + e.MouseMove.RelativeY) / (float)m_Window->GetHeight() * height);
			s.relX = e.MouseMove.RelativeX;
			s.relY = e.MouseMove.RelativeY;
			Mouse::SetState(s);
		}
		else if (e.Type == Enum::EventType::MouseClick)
		{
			MouseState s = Mouse::GetState();
			s.X = (int)(e.MouseButton.X / (float)m_Window->GetWidth() * width);
			s.Y = (int)(e.MouseButton.Y / (float)m_Window->GetHeight() * height);
			if (e.MouseButton.Button < 4)
				s.mouseButtons[e.MouseButton.Button] = true;
			Mouse::SetState(s);
		}
		else if (e.Type == Enum::EventType::MouseRelease)
		{
			MouseState s = Mouse::GetState();
			s.X = (int)(e.MouseButton.X / (float)m_Window->GetWidth() * width);
			s.Y = (int)(e.MouseButton.Y / (float)m_Window->GetHeight() * height);
			if (e.MouseButton.Button < 4)
				s.mouseButtons[e.MouseButton.Button] = false;
			Mouse::SetState(s);
		}
		Update();
		Render();
	}
	Unload();
	m_Renderer->Dispose();
	m_Window->Dispose();
	delete m_Window;
	delete m_Renderer;
}