#pragma once
#include <Rekd2D.h>
#include <iostream>

using namespace Rekd2D::Core;

class MainWindow : public Game
{
public:
	MainWindow();

	void Init();
	void Load();
	void Update(unsigned int time);
	void Render(unsigned int time);
	void Unload();
};