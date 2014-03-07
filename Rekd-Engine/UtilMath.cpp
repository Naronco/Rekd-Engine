#include "UtilMath.h"

Rekd2D::Core::UtilMath::UtilMath()
{
}

unsigned int Rekd2D::Core::UtilMath::Factorial(unsigned int n)
{
	if (n > 1) return n * Factorial(n - 1);
	return 1;
}