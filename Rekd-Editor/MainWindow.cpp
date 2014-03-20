#include "MainWindow.h"

MainWindow::MainWindow()
{
}

void MainWindow::Load()
{
	for (int x = 0; x < 800; x += 10)
	{
		for (int y = 0; y < 480; y += 10)
		{
			AddCheckbox(x, y);
		}
	}
}

void MainWindow::Deinit()
{
}

void MainWindow::AddCheckbox(int x, int y)
{
	CheckboxComponent* checkbox = new CheckboxComponent();
	checkbox->m_Transform = RectF(x, y, 8, 8);
	AddComponent(checkbox);
}