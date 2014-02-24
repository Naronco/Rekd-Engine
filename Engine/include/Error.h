#ifndef REKD_ERROR_H_
#define REKD_ERROR_H_

namespace Rekd2D
{
	namespace Core
	{
		enum Error : unsigned short
		{
			Success      = 0x00,
			Failed       = 0x01,
			UnknownError = 0x02,
			NotFound     = 0x04
		};
	}
}

#endif