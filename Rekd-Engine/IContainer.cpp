#include "IContainer.h"

Rekd2D::Core::Error Rekd2D::Core::IContainer::AddContainer(IContainer* container)
{
	m_Containers.push_back(container);
	return Error::Success;
}

Rekd2D::Core::Error Rekd2D::Core::IContainer::RemoveContainer(IContainer* container)
{
	for (std::vector<IContainer*>::iterator iter = m_Containers.begin(); iter != m_Containers.end(); ++iter)
	{
		if (*iter == container)
		{
			m_Containers.erase(iter);
			return Error::Success;
		}
	}
	return (Error)(Error::Failed | Error::NotFound);
}

Rekd2D::Core::Error Rekd2D::Core::IContainer::RemoveContainer(int id)
{
	m_Containers.erase(m_Containers.begin() + id);
	return Error::Success;
}