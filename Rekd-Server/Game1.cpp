#include "Game1.h"

Game1::Game1()
{
}

void Game1::Init()
{
	{
		b2Vec2 grav(0.0f, 9.8f);
		world = new b2World(grav);
		b2PolygonShape shape;
		shape.SetAsBox(40, 10);

		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(40, 50);
		groundBodyDef.type = b2_staticBody;
		ground = world->CreateBody(&groundBodyDef);
		ground->CreateFixture(&shape, 0.0f);
	}
}

void Game1::AddCube(int x, int y, int rx, int ry)
{
	b2PolygonShape charShape;
	charShape.SetAsBox(5, 5);
	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position = b2Vec2(x / 10.0f, y / 10.0f);
	bd.linearVelocity = b2Vec2(rx, ry);
	bd.userData = "cube";
	b2Body* body = world->CreateBody(&bd);
	b2FixtureDef fixDef;
	fixDef.shape = &charShape;
	fixDef.density = 4.0f;
	fixDef.friction = 0.8f;
	fixDef.restitution = 0.2f;
	body->CreateFixture(&fixDef);
	bodys.push_back(body);
}

void Game1::AddCircle(int x, int y, int rx, int ry)
{
	b2CircleShape charShape;
	charShape.m_radius = 5;
	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position = b2Vec2(x / 10.0f, y / 10.0f);
	bd.linearVelocity = b2Vec2(rx, ry);
	bd.userData = "circle";
	b2Body* body = world->CreateBody(&bd);
	b2FixtureDef fixDef;
	fixDef.shape = &charShape;
	fixDef.density = 4.0f;
	fixDef.friction = 0.2f;
	fixDef.restitution = 0.8f;
	body->CreateFixture(&fixDef);
	bodys.push_back(body);
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
	bd.linearVelocity = b2Vec2(rx, ry);
	bd.userData = "tri";
	b2Body* body = world->CreateBody(&bd);
	b2FixtureDef fixDef;
	fixDef.shape = &charShape;
	fixDef.density = 4.0f;
	fixDef.friction = 0.8f;
	fixDef.restitution = 0.2f;
	body->CreateFixture(&fixDef);
	bodys.push_back(body);
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
}

void Game1::Unload()
{
	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		world->DestroyBody(bodys[i]);
	}
	bodys.clear();
	world->DestroyBody(ground);
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
	glClear(GL_COLOR_BUFFER_BIT);
	//LoadIdentity();

	b2Vec2 gpos = ground->GetPosition();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(gpos.x * 10 - 400, gpos.y * 10 - 100);
	glVertex2f(gpos.x * 10 + 400, gpos.y * 10 - 100);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(gpos.x * 10 + 400, gpos.y * 10 + 100);
	glVertex2f(gpos.x * 10 - 400, gpos.y * 10 + 100);
	glEnd();

	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		float angle = bodys[i]->GetAngle() * 180 / 3.141f;
		b2Vec2 pos = bodys[i]->GetPosition();

		if (pos.x >= -10 && pos.y >= -10 && pos.x <= 90 && pos.y <= 58)
		{
			glTranslatef(pos.x * 10, pos.y * 10, 0);
			glRotatef(angle, 0, 0, 1);
			glColor3f(0.0f, 0.7f, 0.0f);
			if (bodys[i]->GetUserData() == "cube")
			{
				glBegin(GL_QUADS);
				glVertex2f(-50, -50);
				glVertex2f(50, -50);
				glVertex2f(50, 50);
				glVertex2f(-50, 50);
				glEnd();
			}
			else if (bodys[i]->GetUserData() == "tri")
			{
				glBegin(GL_TRIANGLES);
				glVertex2f(-50, -50);
				glVertex2f(0, 50);
				glVertex2f(50, -50);
				glEnd();
			}
			else if (bodys[i]->GetUserData() == "rope")
			{
				glBegin(GL_QUADS);
				glVertex2f(-5, -1.25f);
				glVertex2f(5, -1.25f);
				glVertex2f(5, 1.25f);
				glVertex2f(-5, 1.25f);
				glEnd();
			}
			else
			{
				glBegin(GL_TRIANGLE_FAN);
				glVertex2f(0, 0);
				for (int i = 0; i <= 60; i++)
				{
					glVertex2f(sinf(i / 60.0f * 3.1415926f * 2) * 50, cosf(i / 60.0f * 3.1415926f * 2) * 50);
				}
				glEnd();
			}
			glRotatef(-angle, 0, 0, 1);
			glTranslatef(-pos.x * 10, -pos.y * 10, 0);
		}
	}
}