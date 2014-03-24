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
	scene = 0;
	m_PostProcess->SetVertex(ReadFile("Media/PostProc.vert", "void main() { gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; }"));
	m_PostProcess->SetFragment(ReadFile("Media/PostProc.frag", "varying vec2 texelSize; uniform sampler2D sampler; void main() { gl_FragColor = vec4(1 - texture2D(sampler, gl_TexCoord[0].st).rgb, 1); }"));
	m_PostProcess->Compile();
	m_PostProcess->AddUniform("texelSize");
	m_PostProcess->Bind();
	m_Shader = new Shader(
		"varying vec4 color; void main() { gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; color = gl_Color; }",
		"varying vec4 color; uniform sampler2D sampler; void main() { gl_FragColor = vec4(texture2D(sampler, gl_TexCoord[0].st).rgb * color.rgb, texture2D(sampler, gl_TexCoord[0].st).a); }"
		);
	m_Font = new FontLoader();
	m_Font->Load("Media/Font.fnt");
}

void Pong::Unload()
{
	if (Content) delete Content;
}

void Pong::Update(unsigned int time)
{
}

void Pong::Render(unsigned int time)
{
	m_PostProcess->Set("texelSize", Vector2F(1 / (float)m_Window->GetWidth(), 1 / (float)m_Window->GetHeight()));
	m_Renderer->Clear(Color(255, 0, 255));
	m_Shader->Bind();
	if (scene == 0)
	{
		Background->Bind();
		m_Renderer->DrawRect(RectF(0, 0, 800, 480), Color(255, 255, 255));
		Button->Bind();
		m_Renderer->DrawRect(RectF(300, 200, 200, 32), Color(255, 255, 255));
		m_Renderer->DrawString("START", Vector2F(400 - m_Font->GetWidth("START", 24) * 0.5f, 205), m_Font, 24, Color(255, 255, 255));
		m_Renderer->DrawString("INSANITY PONG", Vector2F(400 - m_Font->GetWidth("INSANITY PONG", 64) * 0.5f, 50), m_Font, 64, Color(255, 255, 255));
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