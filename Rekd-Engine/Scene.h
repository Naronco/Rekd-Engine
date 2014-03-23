#ifndef REKD_SCENE_H_
#define REKD_SCENE_H_

#include "ContentManager.h"

namespace Rekd2D
{
	namespace Core
	{
		class Scene
		{
		public:
			Scene();

			virtual void Load(ContentManager* content) = 0;
			virtual void Render(unsigned int time) = 0;
			virtual void Update(unsigned int time) = 0;
		protected:
		};
	}
}
#endif