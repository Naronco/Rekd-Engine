#ifndef REKD_MOUSESTATE_H_
#define REKD_MOUSESTATE_H_
namespace Rekd2D
{
	namespace Core
	{
		struct MouseState
		{
			int X, Y;
			int RelX, RelY;
			bool MouseButtons[4];
		};
	}
}
#endif