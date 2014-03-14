#include "Keyboard.h"

Rekd2D::Core::KeyboardState Rekd2D::Core::Keyboard::m_State = Rekd2D::Core::KeyboardState();

Rekd2D::Core::KeyboardState Rekd2D::Core::Keyboard::GetState()
{
	return m_State;
}
void Rekd2D::Core::Keyboard::SetState(KeyboardState s)
{
	m_State = s;
}