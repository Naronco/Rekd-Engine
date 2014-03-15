#include "World.h"

Rekd2D::Core::Physics::World::World(Vector2F gravity) : b2World(b2Vec2(gravity.X, gravity.Y))
{
}

void Rekd2D::Core::Physics::World::Deinit()
{
	for (int i = 0; i < bodies.size(); i++)
	{
		DestroyBody(bodies[i]);
	}
	bodies.clear();
}

b2Body* Rekd2D::Core::Physics::World::AddRigidBody(const b2BodyDef* def)
{
	b2Body* b = CreateBody(def);
	bodies.push_back(b);
	return b;
}

std::vector<b2Body*> Rekd2D::Core::Physics::World::GetBodies() const
{
	return bodies;
}