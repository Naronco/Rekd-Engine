#ifndef REKD_RECT_H_
#define REKD_RECT_H_

namespace Rekd2D
{
	namespace Core
	{
		template <typename T> struct Rect
		{
			T X, Y, Width, Height;

			inline Rect() : X(default(T)), Y(default(T)), Width(default(T)), Height(default(T))
			{
			}

			inline Rect(T X_, T Y_, T Width_, T Height_) : X(X_), Y(Y_), Width(Width_), Height(Height_)
			{
			}
		};

		typedef Rect<float> RectF;
		typedef Rect<int> RectI;
		typedef Rect<double> RectD;
	}
}

#endif