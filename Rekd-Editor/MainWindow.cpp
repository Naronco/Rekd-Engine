#include "MainWindow.h"

MainWindow::MainWindow()
{
}

void MainWindow::Load()
{
	AddCheckbox(32, 32);
}

void MainWindow::Deinit()
{
}

void MainWindow::AddCheckbox(int x, int y)
{
	CheckboxComponent* checkbox = new CheckboxComponent();
	Matrix3x3F transform;
	transform.Rotate(0.9f);
	transform.Translate(100, 0);
	transform.Scale(32, 32);
	checkbox->m_Transform = transform;
	AddComponent(checkbox);
}