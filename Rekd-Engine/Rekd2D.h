#ifndef REKD_REKD_2D_H_
#define REKD_REKD_2D_H_

#include <Box2D\Box2D.h>
#include <SDL_net.h>
#include <gl\glew.h>
#include <SDL_opengl.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"
#include "World.h"
#include "Rect.h"
#include "Shader.h"
#include "Texture.h"
#include "Event.h"
#include "Error.h"
#include "Color.h"
#include "UtilMath.h"
#include "BezierCurve.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Window.h"
#include "Renderer.h"

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