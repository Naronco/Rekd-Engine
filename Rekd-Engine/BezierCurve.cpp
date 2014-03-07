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
	int n = m_Points.size();
	for (int i = 0; i < n; i++)
	{
		b = Math::Factorial(n) / Math::Factorial(i) * Math::Factorial(n - i);
		res += b * pow(1 - t, n) * pow(t, i) * m_Points[i];
	}
	return res;
}