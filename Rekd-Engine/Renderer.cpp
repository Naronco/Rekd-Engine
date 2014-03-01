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

void Rekd2D::Core::Renderer::DrawRect(float x, float y, float width, float height)
{
	glTexCoord2f(0, 0);
	glVertex2f(x, y);
	glTexCoord2f(1, 0);
	glVertex2f(x + width, y);
	glTexCoord2f(1, 1);
	glVertex2f(x + width, y + height);
	glTexCoord2f(0, 1);
	glVertex2f(x, y + height);
}