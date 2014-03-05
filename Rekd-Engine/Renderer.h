#ifndef REKD_RENDERER_H_
#define REKD_RENDERER_H_

#include <GL/glew.h>
#include <SDL_opengl.h>
#include <SDL.h>
#include "Error.h"
#include "Window.h"

namespace Rekd2D
{
	namespace Core
	{
		class Renderer
		{
		public:
			/// <summary>Creates a Renderer</summary>
			/// <param name="window">Reference to a Window</param>
			Renderer(Window* window);
			/// <summary>Begins drawing to the window</summary>
			Error Begin();
			/// <summary>Renders output to the window</summary>
			Error End();
			/// <summary>Renders a Rectangle to output</summary>
			/// <param name="x">X-Position relative to top left</param>
			/// <param name="y">Y-Position relative to top left</param>
			/// <param name="width">Width of the Rectangle</param>
			/// <param name="height">Height of the Rectangle</param>
			/// <param name="u">Texture Coordinate X</param>
			/// <param name="v">Texture Coordinate Y</param>
			/// <param name="uvw">Width of Texture in percent</param>
			/// <param name="uvh">Height of Texture in percent</param>
			void DrawRect(float x, float y, float width, float height, float u = 0, float v = 0, float uvw = 1, float uvh = 1);
			/// <summary>Converts a Surface to a Texture</summary>
			/// <param name="surf">Surface to be converted</param>
			int SurfaceToTexture(SDL_Surface* surf);
			/// <summary>Disposes the Context</summary>
			void Dispose();
		protected:
			bool m_IsDrawing = false;
			SDL_GLContext m_Context;
			Window* m_Window;
			GLuint m_FrameBuffer;
		};
	}
}

#endif