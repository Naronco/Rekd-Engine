#include "PictureComponent.h"

Rekd2D::Core::PictureComponent::PictureComponent()
{
}

void Rekd2D::Core::PictureComponent::Load(ContentManager* content)
{
}

Rekd2D::Core::RectF Rekd2D::Core::PictureComponent::GetBounds()
{
	return RectF(m_Transform.GetTranslation(), m_Texture->GetSize());
}

void Rekd2D::Core::PictureComponent::Render(Renderer* renderer)
{
}

void Rekd2D::Core::PictureComponent::SetFlag(unsigned int type, unsigned int value)
{
}

void Rekd2D::Core::PictureComponent::Click(unsigned char button)
{
	OnClick->Run();
}

unsigned int Rekd2D::Core::PictureComponent::GetFlags()
{
	return 0;
}

void Rekd2D::Core::PictureComponent::LoadTexture(std::string file)
{
	m_Texture = new Texture();
	m_Texture->Load(file);
}