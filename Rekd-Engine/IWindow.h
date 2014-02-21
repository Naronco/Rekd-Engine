#ifndef REKD_IWINDOW_H_
#define REKD_IWINDOW_H_

#include <string>
#include "IRenderableContainer.h"

namespace Rekd2D
{
	namespace Core
	{
		class IWindow : public IRenderableContainer
		{
		public:
			std::string m_Title;
		};
	}
}

#endif