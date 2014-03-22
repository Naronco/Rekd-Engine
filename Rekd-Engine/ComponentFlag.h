#ifndef REKD_COMPONENTFLAG_H_
#define REKD_COMPONENTFLAG_H_
namespace Rekd2D
{
	namespace Core
	{
		namespace ComponentFlag
		{
			enum ComponentFlags : int
			{
				Hoverable = 1 << 0,
				Pushable = 1 << 1,
				Focusable = 1 << 2,
				HookKeyboard = 1 << 3,
				HookText = 1 << 4
			};
		}
	}
}
#endif