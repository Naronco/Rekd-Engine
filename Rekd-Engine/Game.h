#ifndef REKD_GAME_H_
#define REKD_GAME_H_

#include <iostream>
#include "Window.h"
#include "Renderer.h"
#include "PredefinedShader.h"
#include <SDL.h>
#include <gl\glew.h>
#include <SDL_opengl.h>
#include <SDL_net.h>
#include <SDL_image.h>
#include "Renderer.h"
#include "Mouse.h"
#include "Keyboard.h"

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
			virtual void KeyDown(bool append, const std::string& text, int cursor, int selection) {}
			///<summary>Entry point for a Game</summary>
			///<param name="title">Window title</param>
			///<param name="width">Window width</param>
			///<param name="height">Window height</param>
			void Run(char* title, unsigned int width, unsigned int height);
			///<summary>Entry point for a Game with viewport</summary>
			///<param name="title">Window title</param>
			///<param name="width">Viewport width</param>
			///<param name="height">Viewport height</param>
			///<param name="windowWidth">Window width</param>
			///<param name="windowHeight">Window height</param>
			void Run(char* title, unsigned int width, unsigned int height, unsigned int windowWidth, unsigned int windowHeight);

			void InitGL(int maj, int min)
			{
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, maj);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, min);
				SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();

				glClearColor(0, 0, 0, 1);
			}

		protected:
			Renderer* m_Renderer;
			Window* m_Window;
			PredefinedShader* m_PostProcess;
		};
	}
}

#endif