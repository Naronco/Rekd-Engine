#ifndef REKD_REKD_2D_H_
#define REKD_REKD_2D_H_

#include <Box2D\Box2D.h>
#include <SDL_net.h>
#include <SDL_opengl.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Window.h"
#include "Renderer.h"
#include "Vector2.h"
#include "BezierCurve.h"
#include "UtilMath.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "World.h"

class Rekd
{
public:
	inline static void InitGL(int maj, int min)
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
};

#endif