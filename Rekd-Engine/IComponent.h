#ifndef REKD_ICOMPONENT_H_
#define REKD_ICOMPONENT_H_

#include "ContentManager.h"
#include "Renderer.h"
#include "Vector2.h"

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
			virtual unsigned int GetFlagID() = 0;

			RectF m_Transform;
		};
	}
}
#endif