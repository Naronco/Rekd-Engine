#ifndef _GAME1_H_
#define _GAME1_H_

#include <Game.h>

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
};

#endif