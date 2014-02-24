#ifndef REKD_ICONTAINER_H_
#define REKD_ICONTAINER_H_

#include <vector>
#include "Error.h"

namespace Rekd2D
{
	namespace Core
	{
		class IContainer
		{
		public:
			/// <summary>
			/// Adds a container. Can only succeed.
			/// </summary>
			/// <param name="container">Container to be added</param>
			virtual Error AddContainer(IContainer* container);
			/// <summary>
			/// Removes a specified container.
			/// </summary>
			/// <param name="container">Container to remove</param>
			virtual Error RemoveContainer(IContainer* container);
			/// <summary>
			/// Removes a container at slot id
			/// </summary>
			/// <param name="id">Slot ID</param>
			virtual Error RemoveContainer(int id);

		protected:
			std::vector<IContainer*> m_Containers;
		};
	}
}

#endif