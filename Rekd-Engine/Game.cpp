#include "Game.h"

void Rekd2D::Core::Game::Run(char* title, unsigned int width, unsigned int height)
{
	Run(title, width, height, width, height);
}

void Rekd2D::Core::Game::Run(char* title, unsigned int width, unsigned int height, unsigned int windowWidth, unsigned int windowHeight)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	InitGL(2, 1);
	m_Window = new Window(title, width, height, windowWidth, windowHeight);
	int err = glewInit();
	if (err != 0) std::cout << "GLEW ERROR " << err << ": " << glewGetErrorString(err) << std::endl;
	Init();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	err = SDLNet_Init();
	if (err != 0) std::cout << "SDLNet ERROR " << err << ": " << SDLNet_GetError() << std::endl;
	err = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
	if (!err) std::cout << "IMG ERROR " << err << ": " << IMG_GetError() << std::endl;
	m_Renderer = new Renderer(m_Window);
	m_Window->GenerateFramebuffer();
	m_PostProcess = new PredefinedShader(
		"void main() { gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; }",
		"uniform sampler2D sampler; void main() { gl_FragColor = texture2D(sampler, gl_TexCoord[0].st); }"
		);
	SDL_StartTextInput();
	Load();
	Event e;
	m_Window->Show();
	unsigned int last = 0, delta = 0;
	unsigned int now;
	MouseState s;
	KeyboardState ks;
	while (m_Window->Update())
	{
		m_Window->BindFramebuffer();
		now = SDL_GetTicks();
		if (now > last)
		{
			delta = now - last;
			last = now;
		}
		while (m_Window->PollEvent(&e))
		{
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
				ks.Mods[e.Keyboard.KeyCode] = e.Keyboard.Modifiers;
				Keyboard::SetState(ks);
			}
			else if (e.Type == Enum::EventType::KeyUp)
			{
				ks.Keys[e.Keyboard.KeyCode] = false;
				ks.Mods[e.Keyboard.KeyCode] = 0;
				Keyboard::SetState(ks);
			}
			else if (e.Type == Enum::EventType::Text)
			{
				KeyDown(e.Text.Append, e.Text.Text, e.Text.Cursor, e.Text.SelectionLength);
			}
		}
		m_Renderer->Clear(Color(43, 78, 124));
		Update(delta);
		Render(delta);

		m_Window->UnbindFramebuffer();
		m_Renderer->Clear(Color(43, 78, 124));
		glLoadIdentity();
		m_PostProcess->Bind();
		m_Window->BindScreentex();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex2f(0, 0);
		glTexCoord2f(1, 1);
		glVertex2f(width, 0);
		glTexCoord2f(1, 0);
		glVertex2f(width, height);
		glTexCoord2f(0, 0);
		glVertex2f(0, height);
		glEnd();
	}
	Unload();
	IMG_Quit();
	SDLNet_Quit();
	m_Renderer->Dispose();
	m_Window->Dispose();
	delete m_Window;
	delete m_Renderer;
	SDL_Quit();
}