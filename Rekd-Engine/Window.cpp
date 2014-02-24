#include "Window.h"

Rekd2D::Core::Window::Window(char* title, unsigned int width, unsigned int height)
{
	m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	if (m_Window) Running = true;
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
		break;
	case SDL_KEYDOWN:
		ne.Type = EventType::KeyDown;
		ne.Keyboard.KeyCode = ev.key.keysym.sym;
		ne.Keyboard.Modifiers = ev.key.keysym.mod;
		ne.Window = ev.key.windowID;
		break;
	case SDL_KEYUP:
		ne.Type = EventType::KeyUp;
		ne.Keyboard.KeyCode = ev.key.keysym.sym;
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
		ne.Type = EventType::MouseClick;
		ne.MouseButton.Button = ev.button.button;
		ne.MouseButton.X = ev.button.x;
		ne.MouseButton.Y = ev.button.y;
		ne.ID = ev.button.which;
		ne.Window = ev.button.windowID;
		break;
	case SDL_MOUSEBUTTONUP:
		ne.Type = EventType::MouseRelease;
		ne.MouseButton.Button = ev.button.button;
		ne.MouseButton.X = ev.button.x;
		ne.MouseButton.Y = ev.button.y;
		ne.ID = ev.button.which;
		ne.Window = ev.button.windowID;
		break;
	case SDL_MOUSEWHEEL:
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
	}
	e = &ne;
	return true;
}

bool Rekd2D::Core::Window::Update(Event* e)
{
	PollEvent(e);

	return Running;
}

void Rekd2D::Core::Window::Dispose()
{
	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}
}