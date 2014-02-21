#ifndef REKD_ICONTAINER_H_
#define REKD_ICONTAINER_H_

#include <list>
#include "Error.h"

namespace Rekd2D
{
	namespace Core
	{
		class IContainer
		{
		public:
			Error AddContainer(IContainer* container);
			Error RemoveContainer(IContainer* container);
			Error RemoveContainer(int id);

		protected:
			std::list<IContainer*> m_Containers;
		};
	}
}

#endif