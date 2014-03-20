#include "Texture.h"

Rekd2D::Core::Texture::Texture()
{
}

void Rekd2D::Core::Texture::Load(const std::string &file, bool flat)
{
	m_Surface = IMG_Load(file.c_str());
	if (!m_Surface)
	{
		std::cout << "Cannot load " << file << std::endl;
	}
	int mode = GL_BITMAP;
	if (m_Surface->format->BitsPerPixel == 24) { // RGB 24bit
		mode = GL_RGB;
	}
	else if (m_Surface->format->BitsPerPixel == 32) { // RGBA 32bit
		mode = GL_RGBA;
	}
	else if (m_Surface->format->BitsPerPixel == 8) { // ??? 8bit
		mode = GL_BITMAP;
	}
	std::cout << (int)m_Surface->format->BitsPerPixel << std::endl;
	glGenTextures(1, &m_TextureId);
	glBindTexture(GL_TEXTURE_2D, m_TextureId);
	glTexImage2D(GL_TEXTURE_2D, 0, mode, m_Surface->w, m_Surface->h, 0, mode, GL_UNSIGNED_BYTE, m_Surface->pixels);
	if (flat)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
}

void Rekd2D::Core::Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_TextureId);
}

void Rekd2D::Core::Texture::Unload()
{
	SDL_FreeSurface(m_Surface);
	glDeleteTextures(1, &m_TextureId);
}