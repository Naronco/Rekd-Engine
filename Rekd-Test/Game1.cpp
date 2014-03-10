#include "Game1.h"

Game1::Game1()
{
}

void Game1::Init()
{
	{
		b2Vec2 grav(0.0f, 10);
		world = new b2World(grav);
		b2PolygonShape shape;
		shape.SetAsBox(40, 10);

		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(-1, 30);
		groundBodyDef.type = b2_staticBody;
		ground = world->CreateBody(&groundBodyDef);
		ground->CreateFixture(&shape, 0.0f);

		b2BodyDef groundBodyDef2;
		groundBodyDef2.position.Set(10, 50);
		groundBodyDef2.type = b2_staticBody;
		ground2 = world->CreateBody(&groundBodyDef2);
		ground2->CreateFixture(&shape, 0.0f);
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
	float deg = atan2(x - rx, y - ry);
	bd.angularVelocity = deg;
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
	b2Body* body = world->CreateBody(&bd);
	b2FixtureDef fixDef;
	fixDef.shape = &charShape;
	fixDef.density = 4.0f;
	fixDef.friction = 0.2f;
	fixDef.restitution = 0.8f;
	body->CreateFixture(&fixDef);
	bodys.push_back(body);
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
	world->DestroyBody(ground2);
	delete world;
}

void Game1::Update()
{
	MouseState cState = Mouse::GetState();
	world->Step(1 / 60.0f, 6, 2);
	if (cState.mouseButtons[0] && !oldState.mouseButtons[0])
	{
		AddCube(cState.X, cState.Y, cState.relX, cState.relY);
	}
	if (cState.mouseButtons[1] && !oldState.mouseButtons[1])
	{
		//AddCircle(cState.X, cState.Y);
		AddCube(cState.X, cState.Y, cState.relX, cState.relY);
	}
	oldState = cState;
}

void Game1::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//LoadIdentity();

	b2Vec2 gpos = ground->GetPosition();
	b2Vec2 gpos2 = ground2->GetPosition();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(gpos.x * 10 - 400, gpos.y * 10 - 100);
	glVertex2f(gpos.x * 10 + 400, gpos.y * 10 - 100);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(gpos.x * 10 + 400, gpos.y * 10 + 100);
	glVertex2f(gpos.x * 10 - 400, gpos.y * 10 + 100);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(gpos2.x * 10 - 400, gpos2.y * 10 - 100);
	glVertex2f(gpos2.x * 10 + 400, gpos2.y * 10 - 100);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(gpos2.x * 10 + 400, gpos2.y * 10 + 100);
	glVertex2f(gpos2.x * 10 - 400, gpos2.y * 10 + 100);
	glEnd();

	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		float angle = bodys[i]->GetAngle() * 180 / 3.141f;
		b2Vec2 pos = bodys[i]->GetPosition();

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
		else
		{
			glBegin(GL_TRIANGLE_FAN);
			glVertex2f(0, 0);
			for (int i = 0; i <= 16; i++)
			{
				glVertex2f(sinf(i / 16.0f * 3.1415926f * 2) * 50, cosf(i / 16.0f * 3.1415926f * 2) * 50);
			}
			glEnd();
		}
		glRotatef(-angle, 0, 0, 1);
		glTranslatef(-pos.x * 10, -pos.y * 10, 0);
	}
}