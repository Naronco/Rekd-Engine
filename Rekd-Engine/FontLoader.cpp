#include "FontLoader.h"

Rekd2D::Core::FontLoader::FontLoader()
{
}

bool Rekd2D::Core::FontLoader::Load(const std::string& file)
{
	std::ifstream f(file);

	if (f.is_open())
	{
		f.ignore(1024, '\n');
		f.ignore(20, '=');
		f >> lineHeight;
		f.ignore(20, '=');
		f.ignore(20, '=');
		f >> m_Width;
		f.ignore(20, '=');
		f >> m_Height;
		std::cout << m_Width << "x" << m_Height << std::endl;
		f.ignore(1024, '\n');
		bool pages = true;
		while (pages)
		{
			std::string type;
			char t;
			while ((f.peek() != ' ') && (f >> t)) type += t;
			if (type == "page")
			{
				f.ignore(6, '=');
				int id;
				f >> id;
				f.ignore(10, '"');
				std::string texFile;
				char x;
				while ((f.peek() != '"') && (f >> x)) texFile += x;
				Texture* tex = new Texture();
				tex->Load(texFile);
				m_Maps.insert(std::pair<unsigned int, Texture*>(id, tex));
				//std::cout << "Another Page" << std::endl;
			}
			else pages = false;
		}
		f.ignore(30, '=');
		int count;
		f >> count;
		//std::cout << count << " Letters" << std::endl;
		f.ignore(4, '\n');
		for (int i = 0; i < count && !f.eof(); i++)
		{
			f.ignore(20, '=');
			unsigned int id;
			f >> id;
			f.ignore(20, '=');
			int x;
			f >> x;
			f.ignore(20, '=');
			int y;
			f >> y;
			f.ignore(20, '=');
			int width;
			f >> width;
			f.ignore(20, '=');
			int height;
			f >> height;
			f.ignore(20, '=');
			int xoff;
			f >> xoff;
			f.ignore(20, '=');
			int yoff;
			f >> yoff;
			f.ignore(20, '=');
			int xadv;
			f >> xadv;
			f.ignore(20, '=');
			int page;
			f >> page;
			f.ignore(20, '=');
			int chnl;
			f >> chnl;

			BMChar bmc = BMChar();
			bmc.chnl = chnl;
			bmc.height = height;
			bmc.page = page;
			bmc.width = width;
			bmc.x = x;
			bmc.xadvance = xadv;
			bmc.xoffset = xoff;
			bmc.y = y;
			bmc.yoffset = yoff;

			//std::cout << "Letter " << x << " " << y << " " << width << " " << height << " " << xoff << " " << yoff << " " << xadv << " " << page << " " << chnl << std::endl;

			m_Characters.insert(std::pair<unsigned int, BMChar>(id, bmc));
		}
		return true;
	}
	else return false;
}

Rekd2D::Core::RectF Rekd2D::Core::FontLoader::GetTextureCoords(unsigned int c)
{
	std::map<unsigned int, BMChar>::iterator it = m_Characters.find(c);
	if (it == m_Characters.end())
	{
		return RectF(0, 0, 0, 0);
	}
	return RectF(m_Characters[c].x / (float)m_Width, m_Characters[c].y / (float)m_Height, m_Characters[c].width / (float)m_Width, m_Characters[c].height / (float)m_Height);
}

Rekd2D::Core::Texture* Rekd2D::Core::FontLoader::GetTexture(unsigned int c)
{
	std::map<unsigned int, BMChar>::iterator it = m_Characters.find(c);
	if (it == m_Characters.end())
	{
		return m_Maps[0];
	}
	return m_Maps[m_Characters[c].page];
}

Rekd2D::Core::BMChar Rekd2D::Core::FontLoader::GetData(unsigned int c)
{
	std::map<unsigned int, BMChar>::iterator it = m_Characters.find(c);
	if (it == m_Characters.end())
	{
		return BMChar();
	}
	return m_Characters[c];
}

float Rekd2D::Core::FontLoader::GetWidth(const std::string& text, float tHeight)
{
	int x = 0;
	float scale = tHeight / (float)lineHeight;
	for (int i = 0; i < text.length(); i++)
	{
		x += GetData(text[i]).xadvance;
	}
	return x * scale;
}