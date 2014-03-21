#include "RunnableWindow.h"

void Rekd2D::Core::RunnableWindow::Init()
{
	m_ContentManager = new ContentManager("");
	m_DefaultShader = new PredefinedShader(
		"varying vec4 color; void main() { gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; color = gl_Color; }",
		"varying vec4 color; uniform sampler2D sampler; void main() { gl_FragColor = vec4(texture2D(sampler, gl_TexCoord[0].st).rgb * color.rgb, texture2D(sampler, gl_TexCoord[0].st).a); }");
}

void Rekd2D::Core::RunnableWindow::Update(unsigned int time)
{
}

void Rekd2D::Core::RunnableWindow::Render(unsigned int time)
{
	m_DefaultShader->Bind();
	MouseState state = Mouse::GetState();
	KeyboardState ks = Keyboard::GetState();
	bool hit = false;
	for (std::vector<IComponent*>::iterator it = m_Components.begin(); it != m_Components.end(); ++it)
	{
		if ((*it)->GetBounds().Collides(Vector2F(state.X, state.Y)))
		{
			if (!state.MouseButtons[1] && m_OldState.MouseButtons[1])
			{
				(*it)->Click(1);
				if ((ComponentFlag::Focusable & (*it)->GetFlags()) == ComponentFlag::Focusable)
				{
					Unfocus();
					(*it)->SetFlag(ComponentFlag::Focusable, 1);
				}
				else hit = true;
			}
		}
		if ((ComponentFlag::Pushable & (*it)->GetFlags()) == ComponentFlag::Pushable) (*it)->SetFlag(ComponentFlag::Pushable, (*it)->GetBounds().Collides(Vector2F(state.X, state.Y)) && state.MouseButtons[1]);
		if ((ComponentFlag::Hoverable & (*it)->GetFlags()) == ComponentFlag::Hoverable) (*it)->SetFlag(ComponentFlag::Hoverable, (*it)->GetBounds().Collides(Vector2F(state.X, state.Y)));
		if ((ComponentFlag::HookKeyboard & (*it)->GetFlags()) == ComponentFlag::HookKeyboard)
		{
			(*it)->OnKeyboard(ks, m_OldKeyState);
		}
		(*it)->Render(m_Renderer);
	}
	if (hit) Unfocus();
	m_OldKeyState = ks;
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

void Rekd2D::Core::RunnableWindow::Unfocus()
{
	for (std::vector<IComponent*>::iterator it = m_Components.begin(); it != m_Components.end(); ++it)
	{
		if ((ComponentFlag::Focusable & (*it)->GetFlags()) == ComponentFlag::Focusable) (*it)->SetFlag(ComponentFlag::Focusable, 0);
	}
}

void Rekd2D::Core::RunnableWindow::AddComponent(IComponent* component)
{
	component->Load(m_ContentManager);
	m_Components.insert(m_Components.begin(), component);
}