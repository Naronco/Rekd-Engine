#ifndef REKD_MOUSE_H_
#define REKD_MOUSE_H_

#include "MouseState.h"

namespace Rekd2D
{
	namespace Core
	{
		class Mouse
		{
		public:
			static MouseState GetState();
			static void SetState(MouseState s);

		protected:
			static MouseState m_State;
		};
	}
}
#endif