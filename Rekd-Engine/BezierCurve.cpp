#include "BezierCurve.h"

Rekd2D::Core::BezierCurve::BezierCurve()
{
}

void Rekd2D::Core::BezierCurve::AddPoint(Rekd2D::Core::Vector2F point)
{
	m_Points.push_back(point);
}

Rekd2D::Core::Vector2F Rekd2D::Core::BezierCurve::GetPoint(float t)
{
	float b = 0;
	Vector2F res(0, 0);
	int n = m_Points.size() - 1;
	for (int i = 0; i <= n; i++)
	{
		b = (float)((float)UtilMath::Factorial(n) / (float)(UtilMath::Factorial(i) * UtilMath::Factorial(n - i)));
		res += b * powf(1 - t, (float)(n - i)) * powf(t, (float)i) * m_Points[i];
	}
	return res;
}