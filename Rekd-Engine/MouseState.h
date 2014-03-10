#ifndef REKD_MOUSESTATE_H_
#define REKD_MOUSESTATE_H_
namespace Rekd2D
{
	namespace Core
	{
		struct MouseState
		{
			int X, Y;
			int relX, relY;
			bool mouseButtons[4];
		};
	}
}
#endif