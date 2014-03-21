#include "MainWindow.h"

MainWindow::MainWindow()
{
}

void MainWindow::Load()
{
	AddCheckbox(32, 32);
	AddTextbox(32, 70);
	AddTextbox(32, 110);
}

void MainWindow::Deinit()
{
}

void MainWindow::AddCheckbox(int x, int y)
{
	CheckboxComponent* checkbox = new CheckboxComponent();
	Matrix3x3F transform;
	transform.Translate(x, y);
	transform.Scale(32, 32);
	checkbox->m_Transform = transform;
	AddComponent(checkbox);
}

void MainWindow::AddTextbox(int x, int y)
{
	TextboxComponent* textbox = new TextboxComponent();
	Matrix3x3F transform;
	transform.Translate(x, y);
	transform.Scale(128, 32);
	textbox->m_Transform = transform;
	AddComponent(textbox);
}