#pragma once

#include "glad/glad.h"
#include "Utils/Matrix.h"
#include "Utils/Vector.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>



namespace OGLE
{
	//TODO: Make a generic file-reader.
	class Shader
	{
	private:
		uint32_t m_shaderID;
		void Initialize(const std::string& vertexPath, const std::string& fragmentPath, const std::string& geometryPath);

	public:
		Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

		Shader(const std::string& vertexPath, const std::string& fragmentPath, const std::string& geometryPath = "");

		void Bind() const;

		void SetBool(const std::string& name, bool value) const;

		void SetInt(const std::string& name, int value) const;
		void SetVec2(const std::string& name, const Vector2& value) const;

		void SetVec2(const std::string& name, float x, float y) const;
		void SetVec3(const std::string& name, const Vector3& value) const;

		void SetVec3(const std::string& name, float x, float y, float z) const;
		void SetVec4(const std::string& name, const Vector4& value) const;

		void SetVec4(const std::string& name, float x, float y, float z, float w) const;

		void SetMat2(const std::string& name, const Matrix2& mat) const;
		void SetMat3(const std::string& name, const Matrix3& mat) const;
		void SetMat4(const std::string& name, const Matrix4& mat) const;
	};

}
