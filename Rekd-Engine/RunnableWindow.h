#ifndef REKD_RUNNABLEWINDOW_H_
#define REKD_RUNNABLEWINDOW_H_

#include "Game.h"

namespace Rekd2D
{
	namespace Core
	{
		class RunnableWindow : public Game
		{
		public:
			void Init();
			void Load();
			void Update(unsigned int time);
			void Render(unsigned int time);
			void Unload();
			///<summary>Entry point for a Game</summary>
			///<param name="title">Window title</param>
			///<param name="width">Window width</param>
			///<param name="height">Window height</param>
			void Run(char* title, unsigned int width, unsigned int height);

		protected:
			Renderer* m_Renderer;
			Window* m_Window;
			PredefinedShader* m_PostProcess;
		};
	}
}

#endif