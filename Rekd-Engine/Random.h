#ifndef REKD_RANDOM_H_
#define REKD_RANDOM_H_

#include <Windows.h>

namespace Rekd2D
{
	namespace Core
	{
		class Random
		{
		public:
			Random();
			Random(int seed);
			Random(unsigned int seed1, unsigned int seed2, unsigned int seed3, unsigned int seed4);

			unsigned int Next(unsigned int max);
			unsigned long long Next();
			float NextFloat();
			bool NextBool();
		protected:
			unsigned long long x, y, z, w, t;
		};
	}
}
#endif