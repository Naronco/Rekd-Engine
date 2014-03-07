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
	unsigned int b = 0;
	Vector2F res(0, 0);
	int n = m_Points.size();
	for (int i = 0; i < n; i++)
	{
		b = UtilMath::Factorial(n) / UtilMath::Factorial(i) * UtilMath::Factorial(n - i);
		res += b * std::powf(1 - t, n) * std::powf(t, i) * m_Points[i];
	}
	return res;
}