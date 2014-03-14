#ifndef REKD_GAME_H_
#define REKD_GAME_H_

#include "Rekd2D.h"
#include "Renderer.h"

namespace Rekd2D
{
	namespace Core
	{
		class Game
		{
		public:
			virtual void Init() = 0;
			virtual void Load() = 0;
			virtual void Update(unsigned int time) = 0;
			virtual void Render(unsigned int time) = 0;
			virtual void Unload() = 0;
			///<summary>Entry point for a Game</summary>
			///<param name="title">Window title</param>
			///<param name="width">Window width</param>
			///<param name="height">Window height</param>
			void Run(char* title, unsigned int width, unsigned int height);

		protected:
			Renderer* m_Renderer;
			Window* m_Window;
		};
	}
}

#endif