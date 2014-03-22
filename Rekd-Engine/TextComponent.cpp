#include "TextComponent.h"

Rekd2D::Core::TextComponent::TextComponent()
{
}

Rekd2D::Core::RectF Rekd2D::Core::TextComponent::GetBounds()
{
	return RectF(m_Transform.GetTranslation(), m_Transform.GetScale());
}

void Rekd2D::Core::TextComponent::Render(Renderer* renderer)
{
	glRotatef(m_Transform.GetRotation(), 0, 0, 1);
	renderer->DrawString(Text, m_Transform.GetTranslation(), m_Font, LineHeight, Color(0, 0, 0));
	glRotatef(-m_Transform.GetRotation(), 0, 0, 1);
}

void Rekd2D::Core::TextComponent::SetFlag(unsigned int type, unsigned int value)
{
	if (type == ComponentFlag::Focusable) Focused = value == 1;
}

void Rekd2D::Core::TextComponent::Click(unsigned char button)
{
}

void Rekd2D::Core::TextComponent::Load(ContentManager* content)
{
	LineHeight = 12;
}

unsigned int Rekd2D::Core::TextComponent::GetFlags()
{
	return ComponentFlag::Focusable;
}