#ifndef REKD_TEXTURE_H_
#define REKD_TEXTURE_H_

#include "Rekd2D.h"

namespace Rekd2D
{
	namespace Core
	{
		class Texture
		{
		public:
			Texture();
			void Load(const std::string &file);
			void Bind();
			void Unload();
		protected:
			unsigned int m_TextureId;
			SDL_Surface* m_Surface;
		};
	}
}
#endif