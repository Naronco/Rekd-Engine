#include "Game1.h"

Game1::Game1()
{
}

void Game1::Init()
{
	b.AddPoint(Vector2F(0, 0));
	b.AddPoint(Vector2F(100, 500));
	b.AddPoint(Vector2F(300, 300));
	b.AddPoint(Vector2F(100, 0));
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
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 101; i++)
	{
		Vector2F v = b.GetPoint(i * 0.01f);
		glVertex2f(v.X, v.Y);
	}
	glEnd();
}