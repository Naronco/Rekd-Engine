#include "Mouse.h"

Rekd2D::Core::MouseState Rekd2D::Core::Mouse::m_State = Rekd2D::Core::MouseState();

Rekd2D::Core::MouseState Rekd2D::Core::Mouse::GetState()
{
	return m_State;
}
void Rekd2D::Core::Mouse::SetState(MouseState s)
{
	m_State = s;
}