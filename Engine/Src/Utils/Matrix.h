#pragma once
#include "glm/gtc/matrix_transform.hpp"
namespace OGLE
{
	typedef glm::mat2 Matrix2;
	typedef glm::mat3 Matrix3;
	typedef glm::mat4 Matrix4;

	namespace Matrix
	{
		
	template<typename T>
	auto Perspective(T fov, T aspect, T nearClip , T farClip)
	{
		return glm::perspective(fov, aspect, nearClip, farClip);
	}

	auto Translate(const Matrix4& model, const Vector3& delta)
	{
		return glm::translate(model, delta);
	}

	auto Scale(const Matrix4& model, const Vector3& delta)
	{
		return glm::scale(model, delta);
	}

	template<int C, int R, typename T, glm::qualifier Q>
	auto Rotate(const glm::mat<C, R, T, Q>& model, T angle, const Vector3& delta)
	{
		return glm::rotate(model, angle, delta);
	}
	
	auto LookAt(const Vector3& eye, const Vector3& center, const Vector3& up)
	{
		return glm::lookAt(eye, center, up);
	}

	}
}