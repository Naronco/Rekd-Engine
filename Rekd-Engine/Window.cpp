#include "Window.h"

Rekd2D::Core::Window::Window(char* title, unsigned int width, unsigned int height) : Window(title, width, height, width, height)
{
}

Rekd2D::Core::Window::Window(char* title, unsigned int width, unsigned int height, unsigned int wwidth, unsigned int wheight)
{
	m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wwidth, wheight, SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	if (m_Window != NULL)
	{
		m_Width = wwidth;
		m_Height = wheight;
		Running = true;
		m_Context = SDL_GL_CreateContext(m_Window);
		glMatrixMode(GL_PROJECTION);
		glOrtho(0, width, height, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		WindowID = SDL_GetWindowID(m_Window);
	}
}

void Rekd2D::Core::Window::Show()
{
	if (m_Window)
		SDL_ShowWindow(m_Window);
}

void Rekd2D::Core::Window::Hide()
{
	if (m_Window)
		SDL_HideWindow(m_Window);
}

void Rekd2D::Core::Window::Close()
{
	if (m_Window)
		SDL_DestroyWindow(m_Window);
}

Rekd2D::Core::Error Rekd2D::Core::Window::SetFullscreen(bool fullscreen)
{
	if (m_Window) {
		if (SDL_SetWindowFullscreen(m_Window, fullscreen) == 0)
		{
			return Error::Success;
		}
	}
	return Error::Failed;
}

void Rekd2D::Core::Window::Resize(unsigned int width, unsigned int height)
{
	if (m_Window)
		SDL_SetWindowSize(m_Window, width, height);
}

void Rekd2D::Core::Window::SetPosition(int x, int y)
{
	if (m_Window)
		SDL_SetWindowPosition(m_Window, x, y);
}

bool Rekd2D::Core::Window::PollEvent(Event* e)
{
	using namespace Enum;
	SDL_Event ev;
	Event ne = Event();
	if (!SDL_PollEvent(&ev)) return false;
	switch (ev.type)
	{
	case SDL_QUIT:
		ne.Type = EventType::Quit;
		break;
	case SDL_WINDOWEVENT:
		if (ev.window.windowID != WindowID)
			return true;
		ne.Type = EventType::Window;
		ne.WindowEvent.Data1 = ev.window.data1;
		ne.WindowEvent.Data2 = ev.window.data2;
		ne.WindowEvent.Event = ev.window.event;
		ne.Window = ev.window.windowID;
		if (ev.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			Running = false;
		}
		if (ev.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
		{
			Focused = true;
		}
		if (ev.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
		{
			Focused = false;
		}
		if (ev.window.event == SDL_WINDOWEVENT_RESIZED)
		{
			m_Width = ev.window.data1;
			m_Height = ev.window.data2;
		}
		break;
	case SDL_KEYDOWN:
		if (ev.key.windowID != WindowID)
			return true;
		ne.Type = EventType::KeyDown;
		ne.Keyboard.KeyCode = (unsigned char)ev.key.keysym.sym;
		ne.Keyboard.Modifiers = ev.key.keysym.mod;
		ne.Window = ev.key.windowID;
		break;
	case SDL_KEYUP:
		if (ev.key.windowID != WindowID)
			return true;
		ne.Type = EventType::KeyUp;
		ne.Keyboard.KeyCode = (unsigned char)ev.key.keysym.sym;
		ne.Keyboard.Modifiers = ev.key.keysym.mod;
		ne.Window = ev.key.windowID;
		break;
	case SDL_MOUSEMOTION:
		ne.Type = EventType::MouseMove;
		ne.MouseMove.DestinationX = ev.motion.x;
		ne.MouseMove.DestinationY = ev.motion.y;
		ne.MouseMove.RelativeX = ev.motion.xrel;
		ne.MouseMove.RelativeY = ev.motion.yrel;
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (ev.button.windowID != WindowID)
			return true;
		ne.Type = EventType::MouseClick;
		ne.MouseButton.Button = ev.button.button;
		ne.MouseButton.X = ev.button.x;
		ne.MouseButton.Y = ev.button.y;
		ne.ID = ev.button.which;
		ne.Window = ev.button.windowID;
		break;
	case SDL_MOUSEBUTTONUP:
		if (ev.button.windowID != WindowID)
			return true;
		ne.Type = EventType::MouseRelease;
		ne.MouseButton.Button = ev.button.button;
		ne.MouseButton.X = ev.button.x;
		ne.MouseButton.Y = ev.button.y;
		ne.ID = ev.button.which;
		ne.Window = ev.button.windowID;
		break;
	case SDL_MOUSEWHEEL:
		if (ev.wheel.windowID != WindowID)
			return true;
		ne.Type = EventType::MouseWheel;
		ne.Scroll.X = ev.wheel.x;
		ne.Scroll.Y = ev.wheel.y;
		ne.ID = ev.wheel.which;
		ne.Window = ev.wheel.windowID;
		break;
	case SDL_JOYAXISMOTION:
		ne.Type = EventType::JoystickAxis;
		ne.CJAxis.Axis = ev.jaxis.axis;
		ne.CJAxis.Value = ev.jaxis.value;
		ne.ID = ev.jaxis.which;
		break;
	case SDL_JOYBALLMOTION:
		ne.Type = EventType::JoystickBall;
		ne.Ball.BallIndex = ev.jball.ball;
		ne.Ball.X = ev.jball.xrel;
		ne.Ball.Y = ev.jball.yrel;
		ne.ID = ev.jball.which;
		break;
	case SDL_JOYHATMOTION:
		ne.Type = EventType::JoystickHat;
		ne.Hat.HatIndex = ev.jhat.hat;
		ne.Hat.Value = ev.jhat.value;
		ne.ID = ev.jhat.which;
		break;
	case SDL_JOYBUTTONDOWN:
		ne.Type = EventType::JoystickButtonDown;
		ne.CJButton.Button = ev.jbutton.button;
		ne.ID = ev.jbutton.which;
		break;
	case SDL_JOYBUTTONUP:
		ne.Type = EventType::JoystickButtonUp;
		ne.CJButton.Button = ev.jbutton.button;
		ne.ID = ev.jbutton.which;
		break;
	case SDL_JOYDEVICEADDED:
		ne.Type = EventType::JoystickAdded;
		ne.ID = ev.jdevice.which;
		break;
	case SDL_JOYDEVICEREMOVED:
		ne.Type = EventType::JoystickRemoved;
		ne.ID = ev.jdevice.which;
		break;
	case SDL_CONTROLLERAXISMOTION:
		ne.Type = EventType::ControllerAxis;
		ne.CJAxis.Axis = ev.caxis.axis;
		ne.CJAxis.Value = ev.caxis.value;
		ne.ID = ev.caxis.which;
		break;
	case SDL_CONTROLLERBUTTONDOWN:
		ne.Type = EventType::ControllerButtonDown;
		ne.CJButton.Button = ev.cbutton.button;
		ne.ID = ev.cbutton.which;
		break;
	case SDL_CONTROLLERBUTTONUP:
		ne.Type = EventType::ControllerButtonUp;
		ne.CJButton.Button = ev.cbutton.button;
		ne.ID = ev.cbutton.which;
		break;
	case SDL_CONTROLLERDEVICEADDED:
		ne.Type = EventType::ControllerAdded;
		ne.ID = ev.cdevice.which;
		break;
	case SDL_CONTROLLERDEVICEREMOVED:
		ne.Type = EventType::ControllerRemoved;
		ne.ID = ev.cdevice.which;
		break;
	case SDL_DROPFILE:
		ne.Type = EventType::DropFile;
		ne.File = ev.drop.file;
		break;
	case SDL_USEREVENT:
		ne.Type = EventType::User;
		ne.User.Code = ev.user.code;
		ne.User.Data1 = ev.user.data1;
		ne.User.Data2 = ev.user.data2;
		break;
	case SDL_TEXTINPUT:
		if (ev.text.windowID == WindowID)
		{
			ne.Type = EventType::Text;
			ne.Text.Append = true;
			ne.Text.Text = std::string(ev.text.text);
		}
		break;
	case SDL_TEXTEDITING:
		if (ev.edit.windowID == WindowID)
		{
			ne.Type = EventType::Text;
			ne.Text.Append = false;
			ne.Text.Text = std::string(ev.text.text);
			ne.Text.Cursor = ev.edit.start;
			ne.Text.SelectionLength = ev.edit.length;
		}
		break;
	default:
		return true;
	}
	*e = ne;
	return true;
}

bool Rekd2D::Core::Window::Update()
{
	SDL_GL_SwapWindow(m_Window);
	return Running;
}

SDL_GLContext Rekd2D::Core::Window::NativeGetContext()
{
	return m_Context;
}

SDL_Window* Rekd2D::Core::Window::GetHandle()
{
	return m_Window;
}

void Rekd2D::Core::Window::Dispose()
{
	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}
}

int Rekd2D::Core::Window::GetWidth()
{
	return m_Width;
}

int Rekd2D::Core::Window::GetHeight()
{
	return m_Height;
}

void Rekd2D::Core::Window::BindFramebuffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
	glOrtho(0, m_FramebufferWidth, m_FramebufferHeight, 0, -1, 1);
	glViewport(0, 0, m_FramebufferWidth, m_FramebufferHeight);
}

void Rekd2D::Core::Window::UnbindFramebuffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glOrtho(0, m_Width, m_Height, 0, -1, 1);
	glViewport(0, 0, m_Width, m_Height);
}

void Rekd2D::Core::Window::GenerateFramebuffer()
{
	SDL_DisplayMode current;
	for (int i = 0; i < SDL_GetNumVideoDisplays(); i++){
		int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);
		if (should_be_zero == 0)
			break;
	}
	glGenFramebuffers(1, &m_Framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
	glGenTextures(1, &m_FramebufferTexture);
	glBindTexture(GL_TEXTURE_2D, m_FramebufferTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, current.w, current.h, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_FramebufferTexture, 0);

	m_FramebufferWidth = current.w;
	m_FramebufferHeight = current.h;
}

void Rekd2D::Core::Window::BindScreentex()
{
	glBindTexture(GL_TEXTURE_2D, m_FramebufferTexture);
}