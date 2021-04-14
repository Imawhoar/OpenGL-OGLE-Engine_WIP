#pragma once
#include "glm/gtc/matrix_transform.hpp"
namespace OGLE
{
	typedef glm::mat2 Matrix2;
	typedef glm::mat3 Matrix3;
	typedef glm::mat4 Matrix4;
	
	namespace Math
	{
		template<typename T>
		auto Perspective(T fov, T aspect, T near, T far)
		{
			return glm::perspective(fov, aspect, near, far);
		}

		template<int VL, int C, int R, typename T, glm::qualifier Q>
		auto Translate(const glm::mat<C, R, T, Q>& model, const glm::vec<VL, T, Q>& delta)
		{
			return glm::translate(model, delta);
		}

		template<int VL, int C, int R, typename T, glm::qualifier Q>
		auto Scale(const glm::mat<C, R, T, Q>& model, const glm::vec<VL, T, Q>& delta)
		{
			return glm::scale(model, delta);
		}

		template<int VL, int C, int R, typename T, glm::qualifier Q>
		auto Rotate(const glm::mat<C, R, T, Q>& model, T angle, const glm::vec<VL, T, Q>& delta)
		{
			return glm::rotate(model, angle, delta);
		}

		template<int L, typename T, glm::qualifier Q>
		auto LookAt(const glm::vec<L, T, Q>& eye, const glm::vec<L, T, Q>& center, const glm::vec<L, T, Q>& up)
		{
			return glm::lookAt(eye, center, up);
		}

	}
}