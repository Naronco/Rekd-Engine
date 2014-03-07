#ifndef REKD_MATH_H_
#define REKD_MATH_H_
#include <cmath>

namespace Rekd2D
{
	namespace Core
	{
		class Math
		{
		public:
			Math();
			static unsigned int Factorial(unsigned int n);
			static double Pow(double x, double y);
		protected:
		};
	}
}
#endif