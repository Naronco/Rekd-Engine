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

				T m[9];
			};

			inline Matrix3x3()
			{

			}

			inline Matrix3x3(T m00_, T m01_, T m02_, T m10_, T m11_, T m12_, T m20_, T m21_, T m22_)
			{
			}

			inline Matrix3x3(T* m_)
			{

			}

			inline Matrix3x3(const Matrix3x3<T>& m)
			{

			}

			inline Matrix3x3<T>& SetIdentity()
			{
				
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

			inline Matrix3x3<T>& Set(T* m)
			{

			}


		};

		typedef Matrix3x3<float> Matrix3x3F;
		typedef Matrix3x3<double> Matrix3x3D;
		typedef Matrix3x3<int> Matrix3x3I;
	}
}

#endif