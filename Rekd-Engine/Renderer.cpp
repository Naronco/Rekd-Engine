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

void Rekd2D::Core::Renderer::DrawRect(Matrix3x3F rect, Color c)
{
	glColor4f(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f, c.A / 255.0f);
	glTranslatef(rect.GetTranslation().x, rect.GetTranslation().y, 0);
	glRotatef(rect.GetRotation() * 180 / 3.1415926f, 0, 0, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(0, 0);
	glTexCoord2f(1, 0);
	glVertex2f(rect.GetScale().x, 0);
	glTexCoord2f(1, 1);
	glVertex2f(rect.GetScale().x, rect.GetScale().y);
	glTexCoord2f(0, 1);
	glVertex2f(0, rect.GetScale().y);
	glEnd();
	glRotatef(-rect.GetRotation() * 180 / 3.1415926f, 0, 0, 1);
	glTranslatef(-rect.GetTranslation().x, -rect.GetTranslation().y, 0);
}

void Rekd2D::Core::Renderer::DrawRect(Matrix3x3F rect, RectF dest, Color c)
{
	glColor4f(c.R / 255.0f, c.G / 255.0f, c.B / 255.0f, c.A / 255.0f);
	glTranslatef(rect.GetTranslation().x, rect.GetTranslation().y, 0);
	glRotatef(rect.GetRotation() * 180 / 3.1415926f, 0, 0, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(dest.X, dest.Y);
	glVertex2f(0, 0);
	glTexCoord2f(dest.X + dest.Width, dest.Y);
	glVertex2f(rect.GetScale().x, 0);
	glTexCoord2f(dest.X + dest.Width, dest.Y + dest.Height);
	glVertex2f(rect.GetScale().x, rect.GetScale().y);
	glTexCoord2f(dest.X, dest.Y + dest.Height);
	glVertex2f(0, rect.GetScale().y);
	glEnd();
	glRotatef(-rect.GetRotation() * 180 / 3.1415926f, 0, 0, 1);
	glTranslatef(-rect.GetTranslation().x, -rect.GetTranslation().y, 0);
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

void Rekd2D::Core::Renderer::Dispose()
{
	SDL_GL_DeleteContext(m_Context);
}

void Rekd2D::Core::Renderer::DrawString(std::string text, Vector2F pos, FontLoader* font, float tHeight, Color c)
{
	int x = 0;
	float scale = tHeight / (float)font->lineHeight;
	for (int i = 0; i < text.length(); i++)
	{
		font->GetTexture(text[i])->Bind();
		DrawRect(RectF(pos + Vector2F(x * scale + font->GetData(text[i]).xoffset * scale, font->GetData(text[i]).yoffset * scale), Vector2F(font->GetData(text[i]).width * scale, font->GetData(text[i]).height * scale)), font->GetTextureCoords(text[i]), c);
		x += font->GetData(text[i]).xadvance;
	}
}