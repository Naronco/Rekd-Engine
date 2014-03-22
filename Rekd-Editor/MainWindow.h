#pragma once
#include <Rekd2D.h>
#include <iostream>

using namespace Rekd2D::Core;

class MainWindow : public RunnableWindow
{
public:
	MainWindow();

	void Load();
	void Deinit();
	void AddCheckbox(int x, int y);
	void AddTextbox(int x, int y);

	FontLoader* font;
};