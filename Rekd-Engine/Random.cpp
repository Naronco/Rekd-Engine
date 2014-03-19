#include "Random.h"

Rekd2D::Core::Random::Random()
{
	x = 45614563LL + GetTickCount64();
	x = 89215656LL + GetTickCount64();
	x = 23452554LL + GetTickCount64();
	x = 16145861LL + GetTickCount64();
}
Rekd2D::Core::Random::Random(int seed)
{
	if (seed < 0) seed = -seed;
	if (seed == 0) seed++;
	x = seed;
	y = seed + 458;
	z = seed + 4756;
	w = seed + 2978;
}
Rekd2D::Core::Random::Random(unsigned int seed1, unsigned int seed2, unsigned int seed3, unsigned int seed4)
{
	if (seed1 == 0) seed1++;
	if (seed2 == 0) seed2++;
	if (seed3 == 0) seed3++;
	if (seed4 == 0) seed4++;
	x = seed1;
	y = seed2;
	z = seed3;
	w = seed4;
}
unsigned long long Rekd2D::Core::Random::Next()
{
	t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}
unsigned int Rekd2D::Core::Random::Next(unsigned int max)
{
	return Next() % max;
}
bool Rekd2D::Core::Random::NextBool()
{
	return Next(2) == 0;
}
float Rekd2D::Core::Random::NextFloat()
{
	return Next(25) / ((float)(1 << 24));
}