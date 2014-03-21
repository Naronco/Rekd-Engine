#ifndef REKD_MATRIX3X3_H_
#define REKD_MATRIX3X3_H_

#include "Vector2.h"

namespace Rekd2D
{
	namespace Core
	{
		/// <summary>A 3x3 Matrix structure</summary>
		template <typename T>
		struct Matrix3x3
		{
			union
			{
				struct
				{
					T m00, m01, m02;
					T m10, m11, m12;
					T m20, m21, m22;
				};

				T m[3][3];
			};

			/// <summary>Initializes the identity matrix</summary>
			inline Matrix3x3()
			{
				SetIdentity();
			}

			/// <summary>Initializes with the given values</summary>
			inline Matrix3x3(T _m00, T _m01, T _m02, T _m10, T _m11, T _m12, T _m20, T _m21, T _m22)
			{
				Set(_m00, _m01, _m02, _m10, _m11, _m12, _m20, _m21, _m22);
			}

			/// <summary>Copies the given matrix</summary>
			/// <param name="m">The source matrix</param>
			inline Matrix3x3(const Matrix3x3<T> &m)
			{
				Set(m);
			}

			/// <summary>Sets the values to the given values</summary>
			inline Matrix3x3<T> &Set(T _m00, T _m01, T _m02, T _m10, T _m11, T _m12, T _m20, T _m21, T _m22)
			{
				m00 = _m00;
				m01 = _m01;
				m02 = _m02;
				m10 = _m10;
				m11 = _m11;
				m12 = _m12;
				m20 = _m20;
				m21 = _m21;
				m22 = _m22;
				return *this;
			}

			/// <summary>Sets the values to the given matrix</summary>
			/// <param name="mat">The target matrix</summary>
			inline Matrix3x3<T> &Set(const Matrix3x3<T> &mat)
			{
				return Set(mat.m00, mat.m01, mat.m02, mat.m10, mat.m11, mat.m12, mat.m20, mat.m21, mat.m22);
			}

			/// <summary>Resets to the identity matrix</summary>
			inline Matrix3x3<T> &SetIdentity()
			{
				return Set(1, 0, 0, 0, 1, 0, 0, 0, 1);
			}

			/// <summary>Multiplies two matrices, and returns a new matrix</summary>
			inline Matrix3x3<T> operator * (const Matrix3x3<T> &mat) const
			{
				Matrix3x3<T> r;

				for (int y = 0; y < 3; y++)
				for (int x = 0; x < 3; x++)
				{
					r.m[x][y] = (m[x][0] * mat.m[0][y]) + (m[x][1] * mat.m[1][y]) + (m[x][2] * mat.m[2][y]);
				}

				return r;
			}

			/// <summary>Multiplies two matrices, and sets the first matrix to the result</summary>
			inline Matrix3x3<T> &operator *= (const Matrix3x3<T> &mat)
			{
				Matrix3x3<T> r;

				for (int y = 0; y < 3; y++)
				for (int x = 0; x < 3; x++)
				{
					r.m[x][y] = (m[x][0] * mat.m[0][y]) + (m[x][1] * mat.m[1][y]) + (m[x][2] * mat.m[2][y]);
				}

				return Set(r);
			}

			/// <summary>Applys the matrix to a vector, and returns a new vector</summary>
			inline Vector2<T> Apply(const Vector2<T> &vec) const
			{
				T rot = atan(m10 / m11);
				T sx = sqrt(m00 * m00 + m01 * m01);
				T sy = sqrt(m10 * m10 + m11 * m11);
				return Vector2<T>(m02 + sx * (cos(rot) * vec.x - sin(rot) * vec.y), m12 + sy * (sin(rot) * vec.x - cos(rot) * vec.y));
			}

			/// <summary>Rotates the matrix over the X axis</summary>
			/// <param name="angle">The amount to rotate in radians</param>
			inline Matrix3x3<T> &Rotate(T angle)
			{
				T s = (T)sin(angle);
				T c = (T)cos(angle);
				return (*this *= Matrix3x3<T>(c, -s, 0, s, c, 0, 0, 0, 1));
			}

			/// <summary>Scales the matrix</summary>
			/// <param name="x">The x scaling</param>
			/// <param name="y">The y scaling</param>
			inline Matrix3x3<T> &Scale(T x, T y)
			{
				return (*this *= Matrix3x3<T>(x, 0, 0, 0, y, 0, 0, 0, 1));
			}

			/// <summary>Translates the matrix</summary>
			/// <param name="x">The x offset</param>
			/// <param name="y">The y offset</param>
			inline Matrix3x3<T> &Translate(T x, T y)
			{
				return (*this *= Matrix3x3<T>(1, 0, x, 0, 1, y, 0, 0, 1));
			}

			/// <summary>Transposes the matrix</summary>
			inline Matrix3x3<T> &Transpose()
			{
				return Set(m00, m10, m20, m01, m11, m21, m02, m12, m22);
			}

			/// <summary>Returns the rotation</summary>
			inline T GetRotation() const
			{
				return (T)atan(m10 / m11);
			}

			/// <summary>Returns the scale</summary>
			inline Vector2<T> GetScale() const
			{
				return Vector2<T>(sqrt(m00 * m00 + m01 * m01), sqrt(m10 * m10 + m11 * m11));
			}

			/// <summary>Returns the translation</summary>
			inline Vector2<T> GetTranslation() const
			{
				return Vector2<T>(m02, m12);
			}
		};

		/*
		template <typename T1, typename T2>
		inline Vector3<T1> &operator *= (const Vector3<T1> &v, const Matrix3x3<T2> &m)
		{
		return v.Set(m.m00 * v.x + m.m01 * v.y + m.m02 * v.z,
		m.m10 * v.x + m.m11 * v.y + m.m12 * v.z,
		m.m20 * v.x + m.m21 * v.y + m.m22 * v.z);
		}

		template <typename T1, typename T2>
		inline Vector3<T1> operator * (const Vector3<T1> &v, const Matrix3x3<T2> &m)
		{
		return Vector3<T1>(m.m00 * v.x + m.m01 * v.y + m.m02 * v.z,
		m.m10 * v.x + m.m11 * v.y + m.m12 * v.z,
		m.m20 * v.x + m.m21 * v.y + m.m22 * v.z);
		}

		template <typename T1, typename T2>
		inline Vector3<T1> operator * (const Matrix3x3<T2> &m, const Vector3<T1> &v)
		{
		return Vector3<T1>(m.m00 * v.x + m.m01 * v.y + m.m02 * v.z,
		m.m10 * v.x + m.m11 * v.y + m.m12 * v.z,
		m.m20 * v.x + m.m21 * v.y + m.m22 * v.z);
		}*/

		typedef Matrix3x3<float> Matrix3x3F;
		typedef Matrix3x3<double> Matrix3x3D;
	}
}
#endif