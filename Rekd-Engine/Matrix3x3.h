#ifndef REKD_VECTOR2_H_
#define REKD_VECTOR2_H_

#include <math.h>

namespace Rekd2D
{
	namespace Core
	{
		template <typename T> struct Matrix3x3
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

			inline Matrix3x3()
			{
				SetIdentity();
			}

			inline Matrix3x3(T m00_, T m01_, T m02_, T m10_, T m11_, T m12_, T m20_, T m21_, T m22_)
			{
				Set(m00_, m01_, m02_, m10_, m11_, m12_, m20_, m21_, m22_);
			}

			inline Matrix3x3(T* m_)
			{
				Set(m_);
			}

			inline Matrix3x3(const Matrix3x3<T>& m)
			{
				Set(m);
			}

			inline Matrix3x3<T>& SetIdentity()
			{
				return Set(1, 0, 0, 0, 1, 0, 0, 0, 1);
			}

			inline Matrix3x3<T>& Set(T m00_, T m01_, T m02_, T m10_, T m11_, T m12_, T m20_, T m21_, T m22_)
			{
				m00 = m00_;
				m01 = m01_;
				m02 = m02_;
				m10 = m10_;
				m11 = m11_;
				m12 = m12_;
				m20 = m20_;
				m21 = m21_;
				m22 = m22_;
			}

			inline Matrix3x3<T>& Set(T* m_)
			{
				Set(m_[0], m_[1], m_[2], m_[3], m_[4], m_[5], m_[6], m_[7], m_[8]);
			}

			inline Matrix3x3<T>& Set(const Matrix3x3<T>& m)
			{
				Set(m.m);
			}

			inline Matrix3x3<T>& SetTranslation(T x, T y)
			{
				return Set(1, 0, x, 0, 1, y, 0, 0, 1);
			}

			inline Matrix3x3<T>& SetRotation(T angle)
			{
				T s = (T)sin(angle);
				T c = (T)cos(angle);
				return Set(c, -s, 0, s, c, 0, 0, 1);
			}

			inline Matrix3x3<T>& SetScaling(T x, T y)
			{
				return Set(x, 0, 0, 0, y, 0, 0, 0, 1);
			}

			inline Matrix3x3<T>& *= (const Matrix3x3<T>& m)
			{
				Matrix3x3<T> r;
				
				for (int y = 0; y < 3; y++)
				{
					for (int x = 0; x < 3; x++)
					{
						r.m[x][y] = (m[y][0] * m.m[0][x]) + (m[y][1] * m.m[1][x]) + (m[y][2] * m.m[2][x]);
					}
				}

				return Set(r);
			}

			inline Matrix3x3<T> * (const Matrix3x3<T>& m) const
			{
				Matrix3x3<T> r;

				for (int y = 0; y < 3; y++)
				{
					for (int x = 0; x < 3; x++)
					{
						r.m[x][y] = (m[y][0] * m.m[0][x]) + (m[y][1] * m.m[1][x]) + (m[y][2] * m.m[2][x]);
					}
				}

				return r;
			}
		};

		typedef Matrix3x3<float> Matrix3x3F;
		typedef Matrix3x3<double> Matrix3x3D;
		typedef Matrix3x3<int> Matrix3x3I;
	}
}

#endif