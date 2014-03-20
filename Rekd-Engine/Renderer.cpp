#include "Renderer.h"

Rekd2D::Core::Renderer::Renderer(Window* window)
{
	m_Context = window->NativeGetContext();
	m_Window = window;
}

void Rekd2D::Core::Renderer::Clear(Color c)
{
	glClearColor(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f, c.A / 255.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Rekd2D::Core::Renderer::DrawRect(RectF rect, Color c)
{
	glColor4f(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f, c.A / 255.0f);
	glTranslatef(rect.X, rect.Y, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(0, 0);
	glTexCoord2f(1, 0);
	glVertex2f(rect.Width, 0);
	glTexCoord2f(1, 1);
	glVertex2f(rect.Width, rect.Height);
	glTexCoord2f(0, 1);
	glVertex2f(0, rect.Height);
	glEnd();
	glTranslatef(-rect.X, -rect.Y, 0);
}

void Rekd2D::Core::Renderer::DrawRect(RectF rect, RectF dest, Color c)
{
	glColor4f(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f, c.A / 255.0f);
	glTranslatef(rect.X, rect.Y, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(dest.X, dest.Y);
	glVertex2f(0, 0);
	glTexCoord2f(dest.X + dest.Width, dest.Y);
	glVertex2f(rect.Width, 0);
	glTexCoord2f(dest.X + dest.Width, dest.Y + dest.Height);
	glVertex2f(rect.Width, rect.Height);
	glTexCoord2f(dest.X, dest.Y + dest.Height);
	glVertex2f(0, rect.Height);
	glEnd();
	glTranslatef(-rect.X, -rect.Y, 0);
}

void Rekd2D::Core::Renderer::DrawRect(RectF rect, RectF dest, Color c, float rota, Vector2F origin)
{
	glColor4f(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f, c.A / 255.0f);
	glTranslatef(origin.x, origin.y, 0);
	glRotatef(rota, 0, 0, 1);
	glTranslatef(rect.X, rect.Y, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(dest.X, dest.Y);
	glVertex2f(0, 0);
	glTexCoord2f(dest.X + dest.Width, dest.Y);
	glVertex2f(rect.Width, 0);
	glTexCoord2f(dest.X + dest.Width, dest.Y + dest.Height);
	glVertex2f(rect.Width, rect.Height);
	glTexCoord2f(dest.X, dest.Y + dest.Height);
	glVertex2f(0, rect.Height);
	glEnd();
	glTranslatef(-rect.X, -rect.Y, 0);
	glRotatef(-rota, 0, 0, 1);
	glTranslatef(-origin.x, -origin.y, 0);
}

int Rekd2D::Core::Renderer::SurfaceToTexture(SDL_Surface* surf)
{
	GLuint TextureID = 0;

	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);

	int Mode = GL_RGB;

	if (surf->format->BytesPerPixel == 4) {
		Mode = GL_RGBA;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, Mode, surf->w, surf->h, 0, Mode, GL_UNSIGNED_BYTE, surf->pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return TextureID;
}

void Rekd2D::Core::Renderer::Dispose()
{
	SDL_GL_DeleteContext(m_Context);
}