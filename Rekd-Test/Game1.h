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

private:
	Random m_Random = 0;
	b2Body* ground = 0;
	b2Body* body = 0;
	b2World* world = 0;
};

#endif