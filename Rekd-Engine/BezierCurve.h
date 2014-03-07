#ifndef REKD_BEZIERCURVE_H_
#define REKD_BEZIERCURVE_H_
#include <vector>
#include "Vector2.h"
#include <math.h>
#include "UtilMath.h"

namespace Rekd2D
{
	namespace Core
	{
		class BezierCurve
		{
		public:
			BezierCurve();
			void AddPoint(Vector2F point);
			Vector2F GetPoint(float t);
		protected:
			std::vector<Vector2F> m_Points;
		};
	}
}
#endif