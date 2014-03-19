#include "Game1.h"

Game1::Game1()
{
}

void Game1::Init()
{
	{
		world = new Physics::World(Vector2F(0, 9.8f));
		b2PolygonShape shape;
		shape.SetAsBox(40, 10);

		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(40, 50);
		groundBodyDef.type = b2_staticBody;
		ground = world->AddRigidBody(&groundBodyDef);
		ground->CreateFixture(&shape, 0.0f);

		AddCube(0, 240, 0, 0, 10, 240, false);
		AddCube(800, 240, 0, 0, 10, 240, false);
		AddCube(400, 0, 0, 0, 400, 10, false);
	}
}

void Game1::AddCube(int x, int y, int rx, int ry, int w, int h, bool dynamic)
{
	b2PolygonShape charShape;
	charShape.SetAsBox(w / 10.0f, h / 10.0f);
	b2BodyDef bd;
	bd.type = dynamic ? b2_dynamicBody : b2_staticBody;
	bd.position = b2Vec2(x / 10.0f, y / 10.0f);
	if (dynamic) bd.linearVelocity = b2Vec2((float)rx, (float)ry);
	bd.userData = "cube";
	b2Body* body = world->AddRigidBody(&bd);
	b2FixtureDef fixDef;
	fixDef.shape = &charShape;
	fixDef.density = 4.0f;
	fixDef.friction = 0.8f;
	fixDef.restitution = 0.2f;
	body->CreateFixture(&fixDef);
}

void Game1::AddCircle(int x, int y, int rx, int ry)
{
	b2CircleShape charShape;
	charShape.m_radius = 5;
	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position = b2Vec2(x / 10.0f, y / 10.0f);
	bd.linearVelocity = b2Vec2((float)rx, (float)ry);
	bd.userData = "circle";
	b2Body* body = world->AddRigidBody(&bd);
	b2FixtureDef fixDef;
	fixDef.shape = &charShape;
	fixDef.density = 1000.0f;
	fixDef.friction = 0.0f;
	fixDef.restitution = 1.0f;
	body->CreateFixture(&fixDef);
}

void Game1::AddTriangle(int x, int y, int rx, int ry)
{
	b2PolygonShape charShape;
	b2Vec2* p = new b2Vec2[3];
	p[0] = b2Vec2(-5, -5);
	p[1] = b2Vec2(0, 5);
	p[2] = b2Vec2(5, -5);
	charShape.Set(p, 3);
	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position = b2Vec2(x / 10.0f, y / 10.0f);
	bd.linearVelocity = b2Vec2((float)rx, (float)ry);
	bd.userData = "tri";
	b2Body* body = world->AddRigidBody(&bd);
	b2FixtureDef fixDef;
	fixDef.shape = &charShape;
	fixDef.density = 4.0f;
	fixDef.friction = 0.8f;
	fixDef.restitution = 0.2f;
	body->CreateFixture(&fixDef);
}

void Game1::AddRope(int x, int y)
{
	/*b2Body* box = 0;
	{
	b2PolygonShape charShape;
	charShape.SetAsBox(5, 5);
	b2BodyDef bd;
	bd.type = b2_staticBody;
	bd.position = b2Vec2(x / 10.0f, y / 10.0f);
	bd.userData = "cube";
	b2FixtureDef fixDef;
	fixDef.shape = &charShape;
	fixDef.density = 4.0f;
	fixDef.friction = 0.8f;
	fixDef.restitution = 0.2f;
	box = world->CreateBody(&bd);
	box->CreateFixture(&fixDef);
	bodys.push_back(box);
	}

	b2RevoluteJoint rev(;
	b2Body* prevBody = box;

	for (int i = 1; i <= 10; i++) {
	// rope segment
	bodyDef = new b2BodyDef();
	bodyDef.position.x = 8.5;
	bodyDef.position.y = i;
	boxDef = new b2PolygonDef();
	boxDef.SetAsBox(0.1, 0.5);
	boxDef.density = 100;
	boxDef.friction = 0.5;
	boxDef.restitution = 0.2;
	body = m_world.CreateBody(bodyDef);
	body.CreateShape(boxDef);
	// joint
	revolute_joint.Initialize(link, body, new b2Vec2(8.5, i - 0.5));
	m_world.CreateJoint(revolute_joint);
	body.SetMassFromShapes();
	// saving the reference of the last placed link
	link = body;
	}*/
}

void Game1::Load()
{
	m_Texture = new Texture();
	m_Texture->Load("test.png");
	m_Shader = new Shader(
		"void main() { gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; }",
		"uniform sampler2D sampler; void main() { gl_FragColor = texture2D(sampler, gl_TexCoord[0].st); }"
		);
	m_Shader->Bind();
	m_PostProcess->SetVertex("void main() { gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; }");
	m_PostProcess->SetFragment("uniform sampler2D sampler; void main() { gl_FragColor = 1 - texture2D(sampler, gl_TexCoord[0].st); }");
	m_PostProcess->Compile();
}

void Game1::Unload()
{
	world->Deinit();
	if (m_Texture)
	{
		m_Texture->Unload();
		delete m_Texture;
	}
	delete world;
}

void Game1::Update(unsigned int time)
{
	KeyboardState cState = Keyboard::GetState();
	MouseState mState = Mouse::GetState();
	world->Step(time * 0.001f, 6, 2);
	if (cState.IsKeyDown(SDLK_y) && !oldState.IsKeyDown(SDLK_y))
	{
		AddCube(mState.X, mState.Y, mState.RelX, mState.RelY);
	}
	if (cState.IsKeyDown(SDLK_x) && !oldState.IsKeyDown(SDLK_x))
	{
		AddCircle(mState.X, mState.Y, mState.RelX * 10, mState.RelY * 10);
	}
	if (cState.IsKeyDown(SDLK_c) && !oldState.IsKeyDown(SDLK_c))
	{
		AddTriangle(mState.X, mState.Y, mState.RelX * 10, mState.RelY * 10);
	}
	if (cState.IsKeyDown(SDLK_v) && !oldState.IsKeyDown(SDLK_v))
	{
		AddRope(mState.X, mState.Y);
	}
	oldState = cState;
}

void Game1::Render(unsigned int time)
{
	m_Renderer->Clear(Color(13, 35, 53));
	m_Texture->Bind();
	m_Shader->Bind();

	b2Vec2 gpos = ground->GetPosition();

	m_Renderer->DrawRect(RectF(gpos.x * 10 - 400, gpos.y * 10 - 100, 800, 200), Color(206, 201, 173));

	for (unsigned int i = 0; i < world->GetBodies().size(); i++)
	{
		float angle = world->GetBodies()[i]->GetAngle() * 180 / 3.141f;
		b2Vec2 pos = world->GetBodies()[i]->GetPosition();

		if (pos.x >= -10 && pos.y >= -10 && pos.x <= 90 && pos.y <= 58)
		{
			glLoadIdentity();
			glTranslatef(pos.x * 10, pos.y * 10, 0);
			glRotatef(angle, 0, 0, 1);
			glColor3f(1, 1, 1);
			if (world->GetBodies()[i]->GetUserData() == "cube")
			{
				glBegin(GL_QUADS);
				glTexCoord2f(0, 0);
				glVertex3f(-50.01f, -50.01f, -0.9f);
				glTexCoord2f(1, 0);
				glVertex3f(50.01f, -50.01f, -0.9f);
				glTexCoord2f(1, 1);
				glVertex3f(50.01f, 50.01f, -0.9f);
				glTexCoord2f(0, 1);
				glVertex3f(-50.01f, 50.01f, -0.9f);
				glEnd();
			}
			else if (world->GetBodies()[i]->GetUserData() == "tri")
			{
				glBegin(GL_TRIANGLES);
				glTexCoord2f(0, 0);
				glVertex2f(-50.01f, -50.01f);
				glTexCoord2f(0.5f, 1);
				glVertex2f(0, 50.01f);
				glTexCoord2f(1, 0);
				glVertex2f(50.01f, -50.01f);
				glEnd();
			}
			else if (world->GetBodies()[i]->GetUserData() == "rope")
			{
				glBegin(GL_QUADS);
				glVertex2f(-5, -1.25f);
				glVertex2f(5, -1.25f);
				glVertex2f(5, 1.25f);
				glVertex2f(-5, 1.25f);
				glEnd();
			}
			else if (world->GetBodies()[i]->GetUserData() == "circle")
			{
				glBegin(GL_TRIANGLE_FAN);
				glTexCoord2f(0.5f, 0.5f);
				glVertex2f(0, 0);
				for (int i = 0; i <= 60; i++)
				{
					glTexCoord2f(sinf(i / 60.0f * 3.1415926f * 2) * 0.5f + 0.5f, cosf(i / 60.0f * 3.1415926f * 2) * 0.5f + 0.5f);
					glVertex2f(sinf(i / 60.0f * 3.1415926f * 2) * 50.01f, cosf(i / 60.0f * 3.1415926f * 2) * 50.01f);
				}
				glEnd();
			}
		}
	}
}