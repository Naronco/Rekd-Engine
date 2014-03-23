#ifndef REKD_CLASS_H_
#define REKD_CLASS_H_
namespace Rekd2D
{
	namespace Core
	{
		class Action
		{
		public:
			virtual void Run() = 0;
		};

		template <typename T>
		class Action1
		{
		public:
			virtual void Run(T arg) = 0;
		};

		template <typename T, typename T2>
		class Action2
		{
		public:
			virtual void Run(T arg, T2 arg2) = 0;
		};
	}
}
#endif