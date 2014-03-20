#ifndef REKD_CONTENTMANAGER_H_
#define REKD_CONTENTMANAGER_H_

#include <algorithm>
#include <map>
#include "Texture.h"

namespace Rekd2D
{
	namespace Core
	{
		class ContentManager
		{
		public:
			ContentManager(const std::string& root);

			/// <summary>Loads a Texture</summary>
			/// <param name="file">Path to the Texture</param>
			Texture* LoadTexture(const std::string& file, bool flat = false);
		protected:
			std::map<std::string, Texture*> m_Textures;
			std::string m_Root;
		};
	}
}
#endif