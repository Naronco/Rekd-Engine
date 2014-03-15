#ifndef REKD_RENDERER_H_
#define REKD_RENDERER_H_

#include <SDL.h>
#include <SDL_opengl.h>
#include "Rect.h"
#include "Color.h"
#include "Error.h"
#include "Window.h"
#include "Vector2.h"

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
			/// <summary>Clears the window</summary>
			/// <param name="c">Color to be cleared</param>
			void Clear(Color c);
			/// <summary>Renders a Rectangle</summary>
			/// <param name="rect">Position and Size</param>
			/// <param name="c">Color</param>
			void DrawRect(RectF rect, Color c);
			/// <summary>Renders a Rectangle</summary>
			/// <param name="rect">Position and Size</param>
			/// <param name="dest">Clipped source</param>
			/// <param name="c">Color</param>
			void DrawRect(RectF rect, RectF dest, Color c);
			/// <summary>Renders a Rectangle</summary>
			/// <param name="rect">Position and Size</param>
			/// <param name="dest">Clipped source</param>
			/// <param name="c">Color</param>
			/// <param name="rota">Rotation</param>
			/// <param name="origin">Rotiation origin</param>
			void DrawRect(RectF rect, RectF dest, Color c, float rota, Vector2F origin);
			/// <summary>Converts a Surface to a Texture</summary>
			/// <param name="surf">Surface to be converted</param>
			int SurfaceToTexture(SDL_Surface* surf);
			/// <summary>Disposes the Context</summary>
			void Dispose();
		protected:
			bool m_IsDrawing = false;
			SDL_GLContext m_Context;
			Window* m_Window;
			unsigned int m_RectId;
		};
	}
}

#endif