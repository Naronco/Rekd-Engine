#include "Pong.h"

Pong::Pong()
{
}

void Pong::Init()
{
}

void Pong::Load()
{
	Content = new ContentManager("Media");
	Background = Content->LoadTexture("bg.png");
	Button = Content->LoadTexture("Button.png");
	Slider = Content->LoadTexture("Slider.png");
	Grabber = Content->LoadTexture("Grabber.png");
	scene = 0;
	m_PostProcess->SetVertex(ReadFile("Media/PostProc.vert", "void main() { gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; }"));
	m_PostProcess->SetFragment(ReadFile("Media/PostProc.frag", "varying vec2 texelSize; uniform sampler2D sampler; void main() { gl_FragColor = vec4(1 - texture2D(sampler, gl_TexCoord[0].st).rgb, 1); }"));
	m_PostProcess->Compile();
	m_PostProcess->AddUniform("texelSize");
	m_PostProcess->AddUniform("neonColor");
	m_PostProcess->Bind();
	m_Shader = new Shader(
		"varying vec4 color; void main() { gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; color = gl_Color; }",
		"varying vec4 color; uniform sampler2D sampler; void main() { gl_FragColor = vec4(texture2D(sampler, gl_TexCoord[0].st).rgb * color.rgb, texture2D(sampler, gl_TexCoord[0].st).a); }"
		);
	m_Font = new FontLoader();
	m_Font->Load("Media/Font.fnt");
	m_Lang = new LanguageLoader();
	m_Lang->Load("Media/game.langs");
	neon.x = 0.75f;
	neon.y = 0.00f;
	neon.z = 1.00f;
}

void Pong::Unload()
{
	if (Content) delete Content;
}

void Pong::Update(unsigned int time)
{
	MouseState ms = Mouse::GetState();
	if (scene == 0)
	{
		if (RectF(300, 200, 200, 32).Collides(Vector2F(ms.X, ms.Y)) && !ms.MouseButtons[1] && oldState.MouseButtons[1])
		{
			scene = 2;
		}
		if (RectF(300, 250, 200, 32).Collides(Vector2F(ms.X, ms.Y)) && !ms.MouseButtons[1] && oldState.MouseButtons[1])
		{
			scene = 1;
		}
	}
	else if (scene == 1)
	{
		if (RectF(300, 150, 200, 20).Collides(Vector2F(ms.X, ms.Y)) && ms.MouseButtons[1])
		{
			neon.x = (ms.X - 300) / 200.0f;
		}
		if (RectF(300, 180, 200, 20).Collides(Vector2F(ms.X, ms.Y)) && ms.MouseButtons[1])
		{
			neon.y = (ms.X - 300) / 200.0f;
		}
		if (RectF(300, 210, 200, 20).Collides(Vector2F(ms.X, ms.Y)) && ms.MouseButtons[1])
		{
			neon.z = (ms.X - 300) / 200.0f;
		}
		if (RectF(300, 300, 200, 32).Collides(Vector2F(ms.X, ms.Y)) && !ms.MouseButtons[1] && oldState.MouseButtons[1])
		{
			scene = 0;
		}
	}
	oldState = ms;
}

void Pong::Render(unsigned int time)
{
	m_PostProcess->Set("texelSize", Vector2F(1 / (float)m_Window->GetWidth(), 1 / (float)m_Window->GetHeight()));
	m_PostProcess->Set("neonColor", neon);
	m_Renderer->Clear(Color(255, 0, 255));
	m_Shader->Bind();
	if (scene == 0)
	{
		Background->Bind();
		m_Renderer->DrawRect(RectF(0, 0, 800, 480), Color(255, 255, 255));
		Button->Bind();
		m_Renderer->DrawRect(RectF(300, 200, 200, 32), Color(255, 255, 255));
		m_Renderer->DrawString(m_Lang->Get("de", "singleplayer", "SINGLEPLAYER"), Vector2F(400 - m_Font->GetWidth(m_Lang->Get("de", "singleplayer", "SINGLEPLAYER"), 24) * 0.5f, 205), m_Font, 24, Color(255, 255, 255));
		Button->Bind();
		m_Renderer->DrawRect(RectF(300, 250, 200, 32), Color(255, 255, 255));
		m_Renderer->DrawString(m_Lang->Get("de", "options", "OPTIONS"), Vector2F(400 - m_Font->GetWidth(m_Lang->Get("de", "options", "OPTIONS"), 24) * 0.5f, 255), m_Font, 24, Color(255, 255, 255));
		m_Renderer->DrawString(m_Lang->Get("de", "name", "INSANITY PONG"), Vector2F(400 - m_Font->GetWidth(m_Lang->Get("de", "name", "INSANITY PONG"), 45) * 0.5f, 50), m_Font, 45, Color(255, 255, 255));
	}
	else if (scene == 1)
	{
		Background->Bind();
		m_Renderer->DrawRect(RectF(0, 0, 800, 480), Color(255, 255, 255));
		Button->Bind();
		m_Renderer->DrawString(m_Lang->Get("de", "options", "OPTIONS"), Vector2F(400 - m_Font->GetWidth(m_Lang->Get("de", "options", "OPTIONS"), 32) * 0.5f, 100), m_Font, 32, Color(255, 255, 255));
		m_Renderer->DrawString(m_Lang->Get("de", "name", "INSANITY PONG"), Vector2F(400 - m_Font->GetWidth(m_Lang->Get("de", "name", "INSANITY PONG"), 45) * 0.5f, 50), m_Font, 45, Color(255, 255, 255));
		Slider->Bind();
		m_Renderer->DrawRect(RectF(300, 150, 200, 20), Color(255, 255, 255));
		m_Renderer->DrawRect(RectF(300, 180, 200, 20), Color(255, 255, 255));
		m_Renderer->DrawRect(RectF(300, 210, 200, 20), Color(255, 255, 255));
		Grabber->Bind();
		m_Renderer->DrawRect(RectF(neon.x * 194 + 294, 150, 20, 20), Color(255, 255, 255));
		m_Renderer->DrawRect(RectF(neon.y * 194 + 294, 180, 20, 20), Color(255, 255, 255));
		m_Renderer->DrawRect(RectF(neon.z * 194 + 294, 210, 20, 20), Color(255, 255, 255));
		std::string rgb = m_Lang->Get("de", "rgb", "RGB");
		m_Renderer->DrawChar(rgb[0], Vector2F(270, 150), m_Font, 18, Color(255, 255, 255));
		m_Renderer->DrawChar(rgb[1], Vector2F(270, 180), m_Font, 18, Color(255, 255, 255));
		m_Renderer->DrawChar(rgb[2], Vector2F(270, 210), m_Font, 18, Color(255, 255, 255));

		Button->Bind();
		m_Renderer->DrawRect(RectF(300, 300, 200, 32), Color(255, 255, 255));
		m_Renderer->DrawString(m_Lang->Get("de", "back", "BACK"), Vector2F(400 - m_Font->GetWidth(m_Lang->Get("de", "back", "BACK"), 24) * 0.5f, 305), m_Font, 24, Color(255, 255, 255));
	}
}

std::string Pong::ReadFile(const std::string &filename, const std::string &fallback)
{
	std::ifstream in(filename, std::ios::in);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	return fallback;
}