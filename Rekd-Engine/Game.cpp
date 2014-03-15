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
	unsigned int last = 0, delta = 0;
	unsigned int now;
	MouseState s;
	KeyboardState ks;
	SDLNet_Init();
	while (m_Window->Update(&e))
	{
		now = SDL_GetTicks();
		if (now > last)
		{
			delta = now - last;
			last = now;
		}
		s = Mouse::GetState();
		ks = Keyboard::GetState();
		if (e.Type == Enum::EventType::MouseMove)
		{
			s.X = (int)((e.MouseMove.DestinationX + e.MouseMove.RelativeX) / (float)m_Window->GetWidth() * width);
			s.Y = (int)((e.MouseMove.DestinationY + e.MouseMove.RelativeY) / (float)m_Window->GetHeight() * height);
			s.RelX = e.MouseMove.RelativeX;
			s.RelY = e.MouseMove.RelativeY;

			Mouse::SetState(s);
		}
		else if (e.Type == Enum::EventType::MouseClick)
		{
			s.X = (int)(e.MouseButton.X / (float)m_Window->GetWidth() * width);
			s.Y = (int)(e.MouseButton.Y / (float)m_Window->GetHeight() * height);
			if (e.MouseButton.Button < 4)
				s.MouseButtons[e.MouseButton.Button] = true;
			Mouse::SetState(s);
		}
		else if (e.Type == Enum::EventType::MouseRelease)
		{
			s.X = (int)(e.MouseButton.X / (float)m_Window->GetWidth() * width);
			s.Y = (int)(e.MouseButton.Y / (float)m_Window->GetHeight() * height);
			if (e.MouseButton.Button < 4)
				s.MouseButtons[e.MouseButton.Button] = false;
			Mouse::SetState(s);
		}
		else if (e.Type == Enum::EventType::KeyDown)
		{
			ks.Keys[e.Keyboard.KeyCode] = true;
			Keyboard::SetState(ks);
		}
		else if (e.Type == Enum::EventType::KeyUp)
		{
			ks.Keys[e.Keyboard.KeyCode] = false;
			Keyboard::SetState(ks);
		}
		Update(delta);
		Render(delta);
	}
	Unload();
	SDLNet_Quit();
	m_Renderer->Dispose();
	m_Window->Dispose();
	delete m_Window;
	delete m_Renderer;
}