#include "Game1.h"

Game1::Game1()
{
}

void Game1::Init()
{
	{
		b2Vec2 grav(0.0f, 10);
		world = new b2World(grav);
		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(-0.5f, 30);
		groundBodyDef.type = b2_staticBody;
		b2PolygonShape shape;
		shape.SetAsBox(40, 10);
		ground = world->CreateBody(&groundBodyDef);
		ground->CreateFixture(&shape, 0.0f);
	}

	b2PolygonShape charShape;
	charShape.SetAsBox(5, 5);
	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position = b2Vec2(40, 0);
	body = world->CreateBody(&bd);
	body->CreateFixture(&charShape, 5.0f);
}

void Game1::Load()
{
}

void Game1::Unload()
{
}

void Game1::Update()
{
	world->Step(1 / 60.0f, 6, 2);
}

void Game1::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//LoadIdentity();

	b2Vec2 gpos = ground->GetPosition();
	float angle = body->GetAngle() * 180 / 3.141f;
	b2Vec2 pos = body->GetPosition();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(gpos.x * 10 - 400, gpos.y * 10 - 100);
	glVertex2f(gpos.x * 10 + 400, gpos.y * 10 - 100);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(gpos.x * 10 + 400, gpos.y * 10 + 100);
	glVertex2f(gpos.x * 10 - 400, gpos.y * 10 + 100);
	glEnd();

	glTranslatef(pos.x * 10, pos.y * 10, 0);
	glRotatef(angle, 0, 0, 1);
	glColor3f(0.0f, 0.7f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(-50, -50);
	glVertex2f(50, -50);
	glVertex2f(50, 50);
	glVertex2f(-50, 50);
	glEnd();
	glRotatef(-angle, 0, 0, 1);
	glTranslatef(-pos.x * 10, -pos.y * 10, 0);
}