#ifndef REKD_COLOR_H_
#define REKD_COLOR_H_
namespace Rekd2D
{
	namespace Core
	{
		struct Color
		{
			unsigned char R, G, B, A;

			Color(unsigned char R, unsigned char G, unsigned char B, unsigned char A) : R(R), G(G), B(B), A(A)
			{ }
			Color(unsigned char R, unsigned char G, unsigned char B) : R(R), G(G), B(B), A(255)
			{ }
		};
	}
}
#endif