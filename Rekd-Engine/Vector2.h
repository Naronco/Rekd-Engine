#ifndef REKD_VECTOR2_H_
#define REKD_VECTOR2_H_

#include <math.h>
#include "Matrix3x3.h"

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

			inline Vector2(const Vector2<T>& v) : X(v.X), Y(v.Y)
			{
			}

			inline Vector2<T>& Clear()
			{
				X = Y = 0;
				return *this;
			}

			inline Vector2<T>& Set(T X_, T Y_)
			{
				X = X_;
				Y = Y_;
				return *this;
			}

			inline Vector2<T>& Set(const Vector2<T>& v)
			{
				X = v.X;
				Y = v.Y;
				return *this;
			}

			inline Vector2<T>& operator += (const Vector2<T>& v)
			{
				return Set(X + v.X, Y + v.Y);
			}

			inline Vector2<T>& operator -= (const Vector2<T>& v)
			{
				return Set(X - v.X, Y - v.Y);
			}

			inline Vector2<T>& operator *= (T value)
			{
				return Set(X * value, Y * value);
			}

			inline Vector2<T>& operator /= (T value)
			{
				T invValue = 1.0 / value;
				return Set(X * invValue, Y * invValue);
			}

			inline Vector2<T> operator + (const Vector2<T>& v) const
			{
				return Vector2<T>(X + v.X, Y + v.Y);
			}

			inline Vector2<T> operator - (const Vector2<T>& v) const
			{
				return Vector2<T>(X - v.X, Y - v.Y);
			}

			inline Vector2<T> operator * (T value) const
			{
				return Vector2<T>(X * value, Y * value);
			}

			inline Vector2<T> operator / (T value) const
			{
				T invValue = 1.0 / value;
				return Vector2<T>(X * invValue, Y * invValue);
			}

			inline bool operator == (const Vector2<T>& v) const
			{
				return (X == v.X) && (Y == v.Y);
			}

			inline bool operator != (const Vector2<T>& v) const
			{
				return (X != v.X) || (Y != v.Y);
			}

			inline T Dot(const Vector2<T>& v) const
			{
				return (X * v.X) + (Y * v.Y);
			}

			inline T Cross(const Vector2<T>& v) const
			{
				return X * v.Y - Y * v.X;
			}

			inline T GetSquaredLength() const
			{
				return X * X + Y * Y;
			}

			inline T GetLength() const
			{
				return (T) sqrt(X * X + Y * Y);
			}

			inline T GetSquaredDistance(const Vector2<T>& v)
			{
				T xd = v.X - X;
				T yd = v.Y - Y;
				return xd * xd + yd * yd;
			}

			inline T GetDistance(const Vector2<T>& v)
			{
				T xd = v.X - X;
				T yd = v.Y - Y;
				return (T) sqrt(xd * xd + yd * yd);
			}

			template <typename S>
			inline Vector2<T>& Lerp(const Vector2<T>& v, S t)
			{
				return (*this += (v - *this) * t);
			}

			inline Vector2<T>& Normalize()
			{
				return (*this *= (1.0 / GetLength()));
			}

			inline Vector2<T> GetNormalized() const
			{
				return (*this * (1.0 / GetLength()));
			}
		};

		typedef Vector2<float> Vector2F;
		typedef Vector2<int> Vector2I;
		typedef Vector2<double> Vector2D;
	}
}

template <typename T>
inline Rekd2D::Core::Vector2<T> operator * (T value, const Rekd2D::Core::Vector2<T>& v)
{
	return Vector2<T>(v.X * value, v.Y * value);
}

template <typename T1, typename T2>
inline Rekd2D::Core::Vector2<T1> operator * (const Rekd2D::Core::Vector2<T1>& v, const Rekd2D::Core::Matrix3x3<T2> &m)
{
	return Vector2<T1>(v.X * m.m00 + v.Y * m.m01 + m.m02, v.X * m.m10 + v.Y * m.m11 + m.m12);
}

template <typename T1, typename T2>
inline Rekd2D::Core::Vector2<T1> operator * (const Rekd2D::Core::Matrix3x3<T2> &m, const Rekd2D::Core::Vector2<T1>& v)
{
	return Vector2<T1>(v.X * m.m00 + v.Y * m.m01 + m.m02, v.X * m.m10 + v.Y * m.m11 + m.m12);
}

template <typename T1, typename T2>
inline Rekd2D::Core::Vector2<T1> operator *= (const Rekd2D::Core::Vector2<T1>& v, const Rekd2D::Core::Matrix3x3<T2> &m)
{
	return v.Set(v.X * m.m00 + v.Y * m.m01 + m.m02, v.X * m.m10 + v.Y * m.m11 + m.m12);
}

#endif