#ifndef REKD_EVENT_H_
#define REKD_EVENT_H_

#include <SDL.h>

namespace Rekd2D
{
	namespace Core
	{
		namespace Enum
		{
			enum EventType
			{
				Quit,
				Window,
				KeyDown,
				KeyUp,
				MouseMove,
				MouseClick,
				MouseRelease,
				MouseWheel,
				JoystickAxis,
				JoystickBall,
				JoystickHat,
				JoystickButtonDown,
				JoystickButtonUp,
				JoystickAdded,
				JoystickRemoved,
				ControllerAxis,
				ControllerButtonDown,
				ControllerButtonUp,
				ControllerAdded,
				ControllerRemoved,
				DropFile,
				User
			};
		}

		struct HatData
		{
			unsigned char Value;
			unsigned char HatIndex;
		};

		struct BallData
		{
			unsigned char BallIndex;
			short X;
			short Y;
		};

		struct ButtonData
		{
			unsigned char Button;
		};

		struct AxisData
		{
			unsigned char Axis;
			short Value;
		};

		struct KeyboardData
		{
			unsigned short Modifiers;
			int KeyCode;
		};

		struct MouseButtonData
		{
			unsigned char Button;
			int X;
			int Y;
		};

		struct ScrollData
		{
			int X;
			int Y;
		};

		struct MotionData
		{
			int DestinationX;
			int DestinationY;
			int RelativeX;
			int RelativeY;
		};

		struct WindowData
		{
			unsigned char Event;
			int Data1;
			int Data2;
		};

		struct UserData
		{
			int Code;
			void* Data1;
			void* Data2;
		};
		
		struct Event
		{
			Enum::EventType Type;
			unsigned int Window;
			unsigned int ID;
			MouseButtonData MouseButton;
			AxisData CJAxis;
			ButtonData CJButton;
			HatData Hat;
			BallData Ball;
			KeyboardData Keyboard;
			ScrollData Scroll;
			MotionData MouseMove;
			WindowData WindowEvent;
			UserData User;
			char* File;
		};
	}
}

#endif