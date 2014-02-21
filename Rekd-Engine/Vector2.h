#ifndef REKD_VECTOR2_H_
#define REKD_VECTOR2_H_

namespace Rekd2D
{
	namespace Core
	{
		template <typename T> struct Vector2
		{
			T X, Y;

			inline Vector2() : X(default(T)), Y(default(T))
			{
			}

			inline Vector2(T X_, T Y_) : X(X_), Y(Y_)
			{
			}

			inline Vector2<T>& operator +=(const Vector2<T>& x)
			{
				X += x.X;
				Y += x.Y;
				return *this;
			}

			inline Vector2<T> operator +(const Vector2<T>& x) const
			{
				return Vector2<T>(X + x.X, Y + x.Y);
			}
		};

		typedef Vector2<float> Vector2F;
		typedef Vector2<int> Vector2I;
		typedef Vector2<double> Vector2D;
	}
}

#endif