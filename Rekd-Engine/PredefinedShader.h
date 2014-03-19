#ifndef REKD_PREDEFINEDSHADER_H_
#define REKD_PREDEFINEDSHADER_H_

#include "Rekd2D.h"
#include <SDL_opengl.h>
#include <map>

namespace Rekd2D
{
	namespace Core
	{
		class PredefinedShader
		{
		public:
			PredefinedShader(const std::string &v, const std::string &f);

			void SetVertex(const std::string &shader);
			void SetFragment(const std::string &shader);
			void Compile();
			void Bind();

			void AddUniform(const std::string &location);

			void Set(const std::string &location, int value);
			void Set(const std::string &location, float value);
			void Set(const std::string &location, Vector2F value);
			void Set(const std::string &location, Vector3F value);
			void Set(const std::string &location, Vector4F value);
			void Set(const std::string &location, Matrix3x3F value);
			void Set(const std::string &location, Matrix4x4F value);

			int GetInt(const std::string &location);
			float GetFloat(const std::string &location);
			Vector2F GetVec2(const std::string &location);
			Vector3F GetVec3(const std::string &location);
			Vector4F GetVec4(const std::string &location);
			Matrix3x3F GetMat3(const std::string &location);
			Matrix4x4F GetMat4(const std::string &location);
		protected:
			std::map<std::string, unsigned int> m_Locations;
			unsigned int m_Program;
			std::string vshader;
			std::string fshader;
		};
	}
}
#endif