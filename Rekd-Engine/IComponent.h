#ifndef REKD_ICOMPONENT_H_
#define REKD_ICOMPONENT_H_

#include "ContentManager.h"
#include "Renderer.h"
#include "Matrix3x3.h"
#include "KeyboardState.h"

namespace Rekd2D
{
	namespace Core
	{
		class IComponent
		{
		public:
			virtual void Load(ContentManager* content) = 0;
			virtual RectF GetBounds() = 0;
			virtual void Render(Renderer* renderer) = 0;
			virtual void SetFlag(unsigned int type, unsigned int value) = 0;
			virtual void Click(unsigned char button) = 0;
			virtual unsigned int GetFlags() = 0;
			virtual void OnKeyboard(KeyboardState ks, KeyboardState old) {}
			virtual void OnText(bool append, const std::string& text, int cursor, int selection) {}

			Matrix3x3F m_Transform;
		};
	}
}
#endif