#ifndef REKD_TEXTURE_H_
#define REKD_TEXTURE_H_

#include <iostream>
#include <string>
#include <SDL.h>
#include <gl\glew.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include "Vector2.h"

namespace Rekd2D
{
	namespace Core
	{
		class Texture
		{
		public:
			Texture();
			bool Load(const std::string &file, bool flat = false);
			void Bind();
			void Unload();

			Vector2F GetSize();
		protected:
			Vector2F m_Size;
			unsigned int m_TextureId = 0;
			SDL_Surface* m_Surface;
		};
	}
}
#endif