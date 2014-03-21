#ifndef REKD_RUNNABLEWINDOW_H_
#define REKD_RUNNABLEWINDOW_H_

#include <vector>
#include "Game.h"
#include "IComponent.h"
#include "ComponentFlag.h"

namespace Rekd2D
{
	namespace Core
	{
		class RunnableWindow : public Game
		{
		public:
			void Init();
			virtual void Load() = 0;
			void Update(unsigned int time);
			void Render(unsigned int time);
			virtual void Deinit() = 0;
			void Unload();

			void AddComponent(IComponent* component);

		protected:
			std::vector<IComponent*> m_Components;
			MouseState m_OldState;
			ContentManager* m_ContentManager;
			PredefinedShader* m_DefaultShader;
		};
	}
}

#endif