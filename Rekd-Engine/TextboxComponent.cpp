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
	if (!Focused)
	{
		Textbox->Bind();
	}
	else
	{
		TextboxFocused->Bind();
	}
	renderer->DrawRect(m_Transform, Color(255, 255, 255));
	m_Label->m_Transform = m_Transform;
	m_Label->Render(renderer);
}

void Rekd2D::Core::TextboxComponent::SetFlag(unsigned int type, unsigned int value)
{
	if (type == ComponentFlag::Focusable) Focused = value == 1;
}

void Rekd2D::Core::TextboxComponent::OnKeyboard(KeyboardState ks, KeyboardState old)
{
	if (Focused)
	{
		for (unsigned char i = 32; i < 127; i++)
		{
			if (ks.IsKeyDown(i) && !old.IsKeyDown(i))
			{
				if (ks.IsKeyDown(SDLK_LSHIFT))
				{
					m_Label->Text += toupper(ks.Keys[i]);
				}
				else
				{
					m_Label->Text += ks.Keys[i];
				}
			}
		}
		if (ks.IsKeyDown(8) && !old.IsKeyDown(8)) m_Label->Text = m_Label->Text.substr(0, m_Label->Text.length() - 1);
	}
}

void Rekd2D::Core::TextboxComponent::Click(unsigned char button)
{
}

void Rekd2D::Core::TextboxComponent::Load(ContentManager* content)
{
	Textbox = content->LoadTexture("TextBox.png", false);
	TextboxFocused = content->LoadTexture("TextBoxActive.png", false);
	m_Label = new TextComponent();
	m_Label->Load(content);
}

unsigned int Rekd2D::Core::TextboxComponent::GetFlags()
{
	return ComponentFlag::Focusable | ComponentFlag::HookKeyboard;
}