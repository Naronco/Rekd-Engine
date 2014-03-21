#include "RunnableWindow.h"

void Rekd2D::Core::RunnableWindow::Init()
{
	m_ContentManager = new ContentManager("");
	m_DefaultShader = new PredefinedShader(
		"void main() { gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; }",
		"uniform sampler2D sampler; void main() { gl_FragColor = texture2D(sampler, gl_TexCoord[0].st); }");
}

void Rekd2D::Core::RunnableWindow::Update(unsigned int time)
{
}

void Rekd2D::Core::RunnableWindow::Render(unsigned int time)
{
	m_DefaultShader->Bind();
	MouseState state = Mouse::GetState();
	for (std::vector<IComponent*>::iterator it = m_Components.begin(); it != m_Components.end(); ++it)
	{
		if ((*it)->GetBounds().Collides(Vector2F(state.X, state.Y)))
		{
			if (!state.MouseButtons[1] && m_OldState.MouseButtons[1]) (*it)->Click(1);
		}
		if ((*it)->GetFlags() & ComponentFlag::Pushable != 0) (*it)->SetFlag(ComponentFlag::Pushable, (*it)->GetBounds().Collides(Vector2F(state.X, state.Y)) && state.MouseButtons[1]);
		if ((*it)->GetFlags() & ComponentFlag::Hoverable != 0) (*it)->SetFlag(ComponentFlag::Pushable, (*it)->GetBounds().Collides(Vector2F(state.X, state.Y)));
		(*it)->Render(m_Renderer);
	}
	m_OldState = state;
}

void Rekd2D::Core::RunnableWindow::Unload()
{
	Deinit();

	for (std::vector<IComponent*>::iterator it = m_Components.begin(); it != m_Components.end(); ++it)
	{
		if (*it) delete (*it);
	}
	m_Components.clear();
}

void Rekd2D::Core::RunnableWindow::AddComponent(IComponent* component)
{
	component->Load(m_ContentManager);
	m_Components.insert(m_Components.begin(), component);
}