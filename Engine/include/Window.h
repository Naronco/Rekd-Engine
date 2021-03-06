#ifndef REKD_WINDOW_H_
#define REKD_WINDOW_H_

#include <SDL.h>
#include "Event.h"
#include "Error.h"

namespace Rekd2D
{
	namespace Core
	{
		class Window
		{
		public:
			/// <summary>Creates a hidden Window</summary>
			/// <param name="title">Title for the Window</param>
			/// <param name="width">Width for the Window</param>
			/// <param name="height">Height for the Window</param>
			Window(char* title, unsigned int width, unsigned int height);
			/// <summary>Shows the Window if it is hidden</summary>
			void Show();
			/// <summary>Hides the Window if it is shown</summary>
			void Hide();
			/// <summary>Closes the Window. Calls the Quit event</summary>
			void Close();
			/// <summary>Disposes all Window data</summary>
			void Dispose();
			/// <summary>Changes the fullscreen state</summary>
			/// <param name="fullscreen">Fullscreen State</param>
			Error SetFullscreen(bool fullscreen);
			/// <summary>Resizes the Window</summary>
			/// <param name="width">Width for the Window</param>
			/// <param name="height">Height for the Window</param>
			void Resize(unsigned int width, unsigned int height);
			/// <summary>Sets the Window position</summary>
			/// <param name="x">Left position relative to top-left</param>
			/// <param name="y">Top position relative to top-left</param>
			void SetPosition(int x, int y);
			/// <summary>Polls latest SDL event</summary>
			bool PollEvent(Event* e);
			/// <summary>Sets the Window title</summary>
			/// <param name="title">Title</param>
			void SetTitle(char* title);
			/// <summary>Gets the Window title</summary>
			char* GetTitle();
			/// <summary>Updates Windows. Checks for Events. Brings the Render to the Window.</summary>
			void Update();
			/// <summary>Checks if Window is Running</summary>
			bool Running;
			/// <summary>Checks if Window got Focus</summary>
			bool Focused;
		protected:
			/// <summary>Handle to a SDL Window</summary>
			SDL_Window* m_Window = 0;
		};
	}
}

#endif