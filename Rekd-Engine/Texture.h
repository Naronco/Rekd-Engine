#ifndef REKD_TEXTURE_H_
#define REKD_TEXTURE_H_

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

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