#include "Renderer.h"

Rekd2D::Core::Renderer::Renderer(Window* window)
{
	m_Context = window->NativeGetContext();
	m_Window = window;
}

Rekd2D::Core::Error Rekd2D::Core::Renderer::Begin()
{
	if (m_IsDrawing) return Error::Failed;
	glClear(GL_COLOR_BUFFER_BIT);
	m_IsDrawing = true;
	glBegin(GL_QUADS);
	return Error::Success;
}

Rekd2D::Core::Error Rekd2D::Core::Renderer::End()
{
	if (!m_IsDrawing) return Error::Failed;
	m_IsDrawing = false;
	glEnd();
	return Error::Success;
}

void Rekd2D::Core::Renderer::DrawRect(float x, float y, float width, float height, float u, float v, float uvw, float uvh)
{
	glTexCoord2f(u, v);
	glVertex2f(x, y);
	glTexCoord2f(uvw, v);
	glVertex2f(x + width, y);
	glTexCoord2f(uvw, uvh);
	glVertex2f(x + width, y + height);
	glTexCoord2f(u, uvh);
	glVertex2f(x, y + height);
}