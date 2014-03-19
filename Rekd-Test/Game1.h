#pragma once

#include <Rekd2D.h>
#include <Game.h>
#include <iostream>
#include <Random.h>

using namespace Rekd2D::Core;

class Game1 : public Game
{
public:
	Game1();
	void Init();
	void Load();
	void Update(unsigned int time);
	void Render(unsigned int time);
	void Unload();
	void AddCircle(int x, int y, int rx, int ry);
	void AddCube(int x, int y, int rx, int ry, int w = 50, int h = 50, bool dynamic = true);
	void AddTriangle(int x, int y, int rx, int ry);
	void AddRope(int x, int y);
	void AddArrow(int x, int y);

private:
	Random m_Random = 0;
	b2Body* ground = 0;
	Physics::World* world = 0;
	KeyboardState oldState;
	Shader* m_Shader;
	Texture* m_Texture;
};