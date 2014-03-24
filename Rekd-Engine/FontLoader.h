#ifndef REKD_FONTLOADER_H_
#define REKD_FONTLOADER_H_

#include <fstream>
#include <string>
#include <map>
#include "Texture.h"
#include "Rect.h"

namespace Rekd2D
{
	namespace Core
	{
		struct BMChar
		{
			int x, y, width, height, xoffset, yoffset, xadvance, page, chnl;
		};

		class FontLoader
		{
		public:
			FontLoader();
			bool Load(const std::string& file);

			Texture* GetTexture(unsigned int c);
			RectF GetTextureCoords(unsigned int c);
			BMChar GetData(unsigned int c);
			float GetWidth(const std::string& text, float tHeight);

			int m_Width, m_Height;
			int lineHeight;
		protected:
			std::map<unsigned int, Texture*> m_Maps;
			std::map<unsigned int, BMChar> m_Characters;
		};
	}
}
#endif