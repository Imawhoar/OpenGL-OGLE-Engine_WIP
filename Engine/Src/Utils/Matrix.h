#pragma once
#include "Vector.h"
#include "glm/gtc/matrix_transform.hpp"
namespace OGLE
{
	using Matrix2 = glm::mat2;
	using Matrix3 = glm::mat3;
	using Matrix4 = glm::mat4;

	template<typename T>
	auto Perspective(T fov, T aspect, T nearClip, T farClip)
	{
		return glm::perspective(fov, aspect, nearClip, farClip);
	}

	inline auto Translate(const Matrix4& model, const Vector3& delta)
	{
		return glm::translate(model, delta);
	}

	inline auto Scale(const Matrix4& model, const Vector3& delta)
	{
		return glm::scale(model, delta);
	}

	template<int C, int R, typename T, glm::qualifier Q>
	auto Rotate(const glm::mat<C, R, T, Q>& model, T angle, const Vector3& delta)
	{
		return glm::rotate(model, angle, delta);
	}

	inline auto LookAt(const Vector3& eye, const Vector3& center, const Vector3& up)
	{
		return glm::lookAt(eye, center, up);
	}
}
