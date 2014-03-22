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
	glBindTexture(GL_TEXTURE_2D, 0);
	Matrix3x3F trans = m_Transform;
	trans.Translate(cursor * 10, 0);
	trans.Scale(selLength * 10, 1);
	renderer->DrawRect(trans, Color(0, 0, 100, 50));
}

void Rekd2D::Core::TextboxComponent::SetFlag(unsigned int type, unsigned int value)
{
	if (type == ComponentFlag::Focusable) Focused = value == 1;
}

void Rekd2D::Core::TextboxComponent::OnText(bool append, const std::string& text, int cursor, int selection)
{
	if (Focused)
	{
		if (append)
		{
			m_Label->Text += text;
		}
		else
		{
			m_Label->Text = text;
		}
	}
}

void Rekd2D::Core::TextboxComponent::OnKeyboard(KeyboardState ks, KeyboardState old)
{
	if (Focused)
	{
		if (ks.Keys[SDLK_BACKSPACE] && !old.Keys[SDLK_BACKSPACE]) m_Label->Text = m_Label->Text.substr(0, std::max(0u, m_Label->Text.length() - 1));
		if (ks.Keys[SDLK_v] && !old.Keys[SDLK_v] && ks.HasControl(SDLK_v))
		{
			HANDLE clip;
			if (OpenClipboard(NULL))
			{
				clip = GetClipboardData(CF_TEXT);
				m_Label->Text += (char*)clip;
			}
		}
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
	m_Label->m_Font = m_Font;
}

unsigned int Rekd2D::Core::TextboxComponent::GetFlags()
{
	return ComponentFlag::Focusable | ComponentFlag::HookText | ComponentFlag::HookKeyboard;
}