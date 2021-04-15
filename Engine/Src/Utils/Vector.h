#pragma once
#include "glm/glm.hpp"
namespace OGLE
{
	typedef glm::vec2 Vector2;
	typedef glm::vec3 Vector3;
	typedef glm::vec4 Vector4;

	template<int L, typename R, glm::qualifier Q>
	float Distance(
		const glm::vec<L, R, Q>& lhs,
		const glm::vec<L, R, Q>& rhs)
	{
		return glm::distance(lhs, rhs);
	}

	template<int L, typename T, glm::qualifier Q>
	float Dot(
		const Vector3& lhs,
		const Vector3& rhs)
	{
		return glm::dot(lhs, rhs);
	}
	template<int L, typename T, glm::qualifier Q>
	float Cross(
		const glm::vec<L, T, Q>& lhs,
		const glm::vec<L, T, Q>& rhs)
	{
		return glm::cross(lhs, rhs);
	}
	template<int L, typename T, glm::qualifier Q>
	float Normalized(const glm::vec<L, T, Q>& lhs)
	{
		return glm::normalize(lhs);
	}
	template<int L, typename T, glm::qualifier Q>
	float Reflect(
		const glm::vec<L, T, Q>& lhs,
		const glm::vec<L, T, Q>& rhs)
	{
		return glm::reflect(lhs, rhs);
	}


}