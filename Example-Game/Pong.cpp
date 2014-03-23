#include "Pong.h"

Pong::Pong()
{
}

void Pong::Init()
{
}

void Pong::Load()
{
	Content = new ContentManager("Media");
}

void Pong::Unload()
{
}

void Pong::Update(unsigned int time)
{
}

void Pong::Render(unsigned int time)
{
	m_Renderer->Clear(Color(10, 10, 10));
}