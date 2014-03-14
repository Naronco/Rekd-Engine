#ifndef REKD_KEYBOARDSTATE_H_
#define REKD_KEYBOARDSTATE_H_
namespace Rekd2D
{
	namespace Core
	{
		struct KeyboardState
		{
			bool Keys[256];

			inline bool IsKeyDown(unsigned char key) const
			{
				return Keys[key];
			}
		};
	}
}
#endif