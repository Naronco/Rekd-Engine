#include "Game1.h"

Game1::Game1()
{
}

void Game1::Init()
{
}

void Game1::Load()
{
}

void Game1::Unload()
{
}

void Game1::Update()
{
}

void Game1::Render()
{
	m_Renderer->Begin();
	m_Renderer->DrawRect(10, 10, 80, 80);
	m_Renderer->End();
}