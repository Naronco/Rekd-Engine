#pragma once

#include <Rekd2D.h>

using namespace Rekd2D::Core;

class Pong : public Game
{
public:
	Pong();
	void Init();
	void Load();
	void Update(unsigned int time);
	void Render(unsigned int time);
	void Unload();

private:
	ContentManager* Content;
};