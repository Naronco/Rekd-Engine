#ifndef REKD_GAME_H_
#define REKD_GAME_H_

namespace Rekd2D
{
	namespace Core
	{
		class IGame
		{
		public:
			virtual void Init() = 0;
			virtual void Load() = 0;
			virtual void Update() = 0;
			virtual void Render() = 0;
			virtual void Unload() = 0;
		};
	}
}

#endif