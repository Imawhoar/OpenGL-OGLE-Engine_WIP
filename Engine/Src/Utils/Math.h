#pragma once
#include <cmath>
#include "glm/fwd.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Vector.h"
#include "Matrix.h"
namespace OGLE::Math
{
	template<typename T>
	inline T Max(T lhs, T rhs) { return lhs > rhs ? lhs : rhs; }
	template<typename T>
	inline T Min(T lhs, T rhs) { return lhs < rhs ? lhs : rhs; }

	template<typename T>
	inline T Abs(T value) { return value < 0 ? -value : value; }

	template<typename T>
	inline T Lerp(T start, T end, T alpha)
	{
		return (1 - alpha) * start + alpha * end;
	}
	template<typename T>
	inline T Clamp(T current, T min, T max)
	{
		min = Min(min, max);
		max = Max(min, max);

		if (current > max)
			return max;
		if (current < min)
			return min;
		return current;
	}

	template<typename T>
	inline T Percent(T current, T min, T max)
	{
		min = Min(min, max);
		max = Max(min, max);

		float retVal = current / max;

		return Clamp(retVal, 0, 1);
	}

	template<typename T>
	inline T Cos(T angle) { return cos(angle); }
	template<typename T>
	inline T Sin(T angle) { return sin(angle); }
	template<typename T>
	inline T Tan(T angle) { return tan(angle); }
	template<typename T>
	inline T Atan2(T deltaX, T deltaY) { return atan2(deltaX, deltaY); }

	template<typename T>
	inline T Sqrt(T value) { return sqrt(value); }
	template<typename T>
	inline T Pow(T value, T pow) { return std::pow(value, pow); }
	template<typename T>
	inline T Pow2(T value) { Pow(value, 2); }

	namespace Vector {

		template<int L, typename R, glm::qualifier Q>
		float Distance(
			const glm::vec<L, R, Q>& lhs,
			const glm::vec<L, R, Q>& rhs)
		{
			return glm::distance(lhs, rhs);
		}

		template<int L, typename T, glm::qualifier Q>
		float Dot(
			const glm::vec<L, T, Q>& lhs,
			const glm::vec<L, T, Q>& rhs)
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
		float Normalize(
			const glm::vec<L, T, Q>& lhs,
			const glm::vec<L, T, Q>& rhs)
		{
			return glm::normalize(lhs, rhs);
		}
		template<int L, typename T, glm::qualifier Q>
		float Reflect(
			const glm::vec<L, T, Q>& lhs,
			const glm::vec<L, T, Q>& rhs)
		{
			return glm::reflect(lhs, rhs);
		}


	}
	namespace Matrix
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
