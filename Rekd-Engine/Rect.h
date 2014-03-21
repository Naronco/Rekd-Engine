#ifndef REKD_RECT_H_
#define REKD_RECT_H_

#include "Vector2.h"

namespace Rekd2D
{
	namespace Core
	{
		template <typename T> struct Rect
		{
			T X, Y, Width, Height;

			inline Rect() : X(0), Y(0), Width(0), Height(0)
			{
			}

			inline Rect(Vector2<T> a, Vector2<T> b) : X(a.x), Y(a.y), Width(b.x), Height(b.y)
			{
			}

			inline Rect(T X_, T Y_, T Width_, T Height_) : X(X_), Y(Y_), Width(Width_), Height(Height_)
			{
			}

			inline bool Collides(Vector2F v)
			{
				return (v.x >= X && v.x <= X + Width && v.y >= Y && v.y <= Y + Height);
			}
		};

		typedef Rect<float> RectF;
		typedef Rect<int> RectI;
		typedef Rect<double> RectD;
	}
}

#endif