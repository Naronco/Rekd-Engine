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
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	glVertex2f(90, 10);
	glVertex2f(70, 10);
	glVertex2f(50, 80);
	glVertex2f(40, 40);
	glEnd();
}