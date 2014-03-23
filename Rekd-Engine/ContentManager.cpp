#include "ContentManager.h"

Rekd2D::Core::ContentManager::ContentManager(const std::string& root)
{
	if (root.length() == 0) m_Root = "";
	else
	{
		m_Root = root + "/";
	}
}

Rekd2D::Core::Texture* Rekd2D::Core::ContentManager::LoadTexture(const std::string& file, bool flat)
{
	std::map<std::string, Texture*>::iterator it = m_Textures.find(file);
	int uniform;
	if (it != m_Textures.end())
	{
		return m_Textures[file];
	}
	Texture* tex = new Texture();
	tex->Load(m_Root + file, flat);
	m_Textures.insert(std::pair<std::string, Texture*>(file, tex));
	return tex;
}