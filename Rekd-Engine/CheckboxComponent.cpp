#include "CheckboxComponent.h"

Rekd2D::Core::CheckboxComponent::CheckboxComponent()
{
}

Rekd2D::Core::RectF Rekd2D::Core::CheckboxComponent::GetBounds()
{
	return RectF(m_Transform.GetTranslation(), m_Transform.GetScale());
}

void Rekd2D::Core::CheckboxComponent::Render(Renderer* renderer)
{
	if (Checked)
	{
		CheckBoxOn->Bind();
	}
	else
	{
		CheckBoxOff->Bind();
	}
	renderer->DrawRect(m_Transform, Color(255, 255, 255));
}

void Rekd2D::Core::CheckboxComponent::SetFlag(unsigned int type, unsigned int value)
{
}

void Rekd2D::Core::CheckboxComponent::Click(unsigned char button)
{
	if (button == 1)
		Checked = !Checked;
}

void Rekd2D::Core::CheckboxComponent::Load(ContentManager* content)
{
	CheckBoxOff = content->LoadTexture("CheckBoxOff.png", false);
	CheckBoxOn = content->LoadTexture("CheckBoxOn.png", false);
}
unsigned int Rekd2D::Core::CheckboxComponent::GetFlags()
{
	return 0;
}