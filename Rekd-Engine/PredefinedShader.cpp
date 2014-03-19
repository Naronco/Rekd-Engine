#include "PredefinedShader.h"
void Rekd2D::Core::PredefinedShader::Set(const std::string &location, int value)
{
	int uniform = m_Locations[location];
	glUniform1i(uniform, value);
}
void Rekd2D::Core::PredefinedShader::Set(const std::string &location, float value)
{
	int uniform = m_Locations[location];
	glUniform1f(uniform, value);
}
void Rekd2D::Core::PredefinedShader::Set(const std::string &location, Vector2F value)
{
	int uniform = m_Locations[location];
	glUniform2fv(uniform, 1, value.xy);
}
void Rekd2D::Core::PredefinedShader::Set(const std::string &location, Vector3F value)
{
	int uniform = m_Locations[location];
	glUniform3fv(uniform, 1, value.xyz);
}
void Rekd2D::Core::PredefinedShader::Set(const std::string &location, Vector4F value)
{
	int uniform = m_Locations[location];
	glUniform4fv(uniform, 1, value.xyzw);
}
void Rekd2D::Core::PredefinedShader::Set(const std::string &location, Matrix3x3F value)
{
	int uniform = m_Locations[location];
	float m[] = { value.m00, value.m01, value.m02, value.m10, value.m11, value.m12, value.m20, value.m21, value.m22 };
	glUniformMatrix3fv(uniform, 1, false, m);
}
void Rekd2D::Core::PredefinedShader::Set(const std::string &location, Matrix4x4F value)
{
	int uniform = m_Locations[location];
	float m[] = { value.m00, value.m01, value.m02, value.m03, value.m10, value.m11, value.m12, value.m13, value.m20, value.m21, value.m22, value.m23, value.m30, value.m31, value.m32, value.m33 };
	glUniformMatrix4fv(uniform, 1, false, m);
}

//  ------------------------------------------------------------------ GETTER ------------------------------------------------------------------

int Rekd2D::Core::PredefinedShader::GetInt(const std::string &location)
{
	int uniform = m_Locations[location];
	int out;
	glGetUniformiv(m_Program, uniform, &out);
	return out;
}
float Rekd2D::Core::PredefinedShader::GetFloat(const std::string &location)
{
	int uniform = m_Locations[location];
	float out;
	glGetUniformfv(m_Program, uniform, &out);
	return out;
}
Rekd2D::Core::Vector2F Rekd2D::Core::PredefinedShader::GetVec2(const std::string &location)
{
	int uniform = m_Locations[location];
	float out[2];
	glGetUniformfv(m_Program, uniform, out);
	return Vector2F(out[0], out[1]);
}
Rekd2D::Core::Vector3F Rekd2D::Core::PredefinedShader::GetVec3(const std::string &location)
{
	int uniform = m_Locations[location];
	float out[3];
	glGetUniformfv(m_Program, uniform, out);
	return Vector3F(out[0], out[1], out[2]);
}
Rekd2D::Core::Vector4F Rekd2D::Core::PredefinedShader::GetVec4(const std::string &location)
{
	int uniform = m_Locations[location];
	float out[4];
	glGetUniformfv(m_Program, uniform, out);
	return Vector4F(out[0], out[1], out[2], out[3]);
}
Rekd2D::Core::Matrix3x3F Rekd2D::Core::PredefinedShader::GetMat3(const std::string &location)
{
	int uniform = m_Locations[location];
	float out[9];
	glGetUniformfv(m_Program, uniform, out);
	return Matrix3x3F(out[0], out[1], out[2],
		out[3], out[4], out[5],
		out[6], out[7], out[8]);
}
Rekd2D::Core::Matrix4x4F Rekd2D::Core::PredefinedShader::GetMat4(const std::string &location)
{
	int uniform = m_Locations[location];
	float out[16];
	glGetUniformfv(m_Program, uniform, out);
	return Matrix4x4F(out[0], out[1], out[2], out[3],
		out[4], out[5], out[6], out[7],
		out[8], out[9], out[10], out[11],
		out[12], out[13], out[14], out[15]);
}

void Rekd2D::Core::PredefinedShader::AddUniform(const std::string &location)
{
	std::map<std::string, unsigned int>::iterator it = m_Locations.find(location);
	if (it == m_Locations.end())
	{
		m_Locations.insert(std::pair<std::string, unsigned int>(location, glGetUniformLocation(m_Program, location.c_str())));
	}
}