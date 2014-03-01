#ifndef REKD_REKD_2D_H_
#define REKD_REKD_2D_H_

#include <SDL.h>
#include <SDL_opengl.h>
#include "Window.h"
#include "Renderer.h"

class Rekd
{
public:
	inline static void InitGL(int min, int max)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, max);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, min);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glClearColor(0, 0, 0, 1);
	}
};

#endif