#ifndef _GAME1_H_
#define _GAME1_H_

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
	void Update();
	void Render();
	void Unload();
	void AddCircle(int x, int y, int rx, int ry);
	void AddCube(int x, int y, int rx, int ry);

private:
	Random m_Random = 0;
	b2Body* ground = 0;
	b2Body* ground2 = 0;
	std::vector<b2Body*> bodys;
	b2World* world = 0;
	MouseState oldState;
};

#endif