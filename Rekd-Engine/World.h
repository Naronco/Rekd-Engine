#ifndef REKD_PHYSICS_H_
#define REKD_PHYSICS_H_

#include "Vector2.h"
#include <vector>
#include <Box2D/Box2D.h>

namespace Rekd2D
{
	namespace Core
	{
		namespace Physics
		{
			class World : public b2World
			{
			public:
				World(Vector2F gravity);
				void Deinit();

				b2Body* AddRigidBody(const b2BodyDef* def);
				b2Joint* AddJoint(const b2JointDef* def);
				std::vector<b2Body*> GetBodies() const;
				std::vector<b2Joint*> GetJoints() const;

			protected:
				std::vector<b2Body*> bodies;
				std::vector<b2Joint*> joints;
			};
		}
	}
}
#endif