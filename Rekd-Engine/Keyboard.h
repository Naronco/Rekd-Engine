#ifndef REKD_KEYBOARD_H_
#define REKD_KEYBOARD_H_

#include "KeyboardState.h"

namespace Rekd2D
{
	namespace Core
	{
		class Keyboard
		{
		public:
			static KeyboardState GetState();
			static void SetState(KeyboardState s);

		protected:
			static KeyboardState m_State;
		};
	}
}
#endif