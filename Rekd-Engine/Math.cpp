#include "Math.h"

Rekd2D::Core::Math::Math()
{
}

unsigned int Rekd2D::Core::Math::Factorial(unsigned int n)
{
	if (n > 1) return n * Factorial(n - 1);
	return 1;
}