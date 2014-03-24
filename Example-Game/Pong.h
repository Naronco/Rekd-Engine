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
	std::string ReadFile(const std::string &filename, const std::string &fallback);

private:
	ContentManager* Content;
	Texture* Background;
	Texture* Button;
	Shader* m_Shader;
	FontLoader* m_Font;
	int scene;
};