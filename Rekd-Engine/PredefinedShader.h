#ifndef REKD_PREDEFINEDSHADER_H_
#define REKD_PREDEFINEDSHADER_H_

#include "Shader.h"

namespace Rekd2D
{
	namespace Core
	{
		class PredefinedShader : public Shader
		{
		public:
			using Shader::Shader;
			using Shader::SetVertex;
			using Shader::SetFragment;
			using Shader::Compile;
			using Shader::Bind;

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
		};
	}
}
#endif