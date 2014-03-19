#include "World.h"

Rekd2D::Core::Physics::World::World(Vector2F gravity) : b2World(b2Vec2(gravity.x, gravity.y))
{
}

void Rekd2D::Core::Physics::World::Deinit()
{
	for (int i = 0; i < joints.size(); i++)
	{
		DestroyJoint(joints[i]);
	}
	joints.clear();
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

b2Joint* Rekd2D::Core::Physics::World::AddJoint(const b2JointDef* def)
{
	b2Joint* j = CreateJoint(def);
	joints.push_back(j);
	return j;
}

std::vector<b2Body*> Rekd2D::Core::Physics::World::GetBodies() const
{
	return bodies;
}

std::vector<b2Joint*> Rekd2D::Core::Physics::World::GetJoints() const
{
	return joints;
}