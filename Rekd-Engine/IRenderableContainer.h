#ifndef REKD_IRENDERABLECONTAINER_H_
#define REKD_IRENDERABLECONTAINER_H_

#include "IContainer.h"
#include "Rect.h"

namespace Rekd2D
{
	namespace Core
	{
		class IRenderableContainer : public IContainer
		{
		public:
			virtual void Render() = 0;

		protected:
			RectI m_DisplayRect;
		};
	}
}

#endif