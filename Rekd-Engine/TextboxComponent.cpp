#include "TextboxComponent.h"

Rekd2D::Core::TextboxComponent::TextboxComponent()
{
}

Rekd2D::Core::RectF Rekd2D::Core::TextboxComponent::GetBounds()
{
	return RectF(m_Transform.GetTranslation(), m_Transform.GetScale());
}

void Rekd2D::Core::TextboxComponent::Render(Renderer* renderer)
{
	if (Focused)
	{
		Textbox->Bind();
	}
	else
	{
		TextboxFocused->Bind();
	}
	/*renderer->DrawRect(m_Transform, RectF(), Color(255, 255, 255));
	renderer->DrawRect(m_Transform, RectF(), Color(255, 255, 255));
	renderer->DrawRect(m_Transform, RectF(), Color(255, 255, 255));
	renderer->DrawRect(m_Transform, RectF(), Color(255, 255, 255));
	renderer->DrawRect(m_Transform, RectF(), Color(255, 255, 255));
	renderer->DrawRect(m_Transform, RectF(), Color(255, 255, 255));
	renderer->DrawRect(m_Transform, RectF(), Color(255, 255, 255));
	renderer->DrawRect(m_Transform, RectF(), Color(255, 255, 255));
	renderer->DrawRect(m_Transform, RectF(), Color(255, 255, 255));*/
}

void Rekd2D::Core::TextboxComponent::SetFlag(unsigned int type, unsigned int value)
{
	if (type == TEXTBOX_FOCUSED) Focused = value == 1;
}

void Rekd2D::Core::TextboxComponent::Click(unsigned char button)
{
}

void Rekd2D::Core::TextboxComponent::Load(ContentManager* content)
{
	Textbox = content->LoadTexture("TextBox.png", false);
	TextboxFocused = content->LoadTexture("TextBoxActive.png", false);
}

unsigned int Rekd2D::Core::TextboxComponent::GetFlags()
{
	return ComponentFlag::Focusable;
}