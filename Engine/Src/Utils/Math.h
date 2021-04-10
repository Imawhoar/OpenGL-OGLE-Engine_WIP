#pragma once
#include <cmath>
#include "glm/glm.hpp"
#include "Vector.h"

namespace OGLE::Math
{
	inline float Max(float lhs, float rhs) { return lhs > rhs ? lhs : rhs; }
	inline float Min(float lhs, float rhs) { return lhs < rhs ? lhs : rhs; }

	inline float Lerp(float start, float end, float alpha)
	{
		return (1 - alpha) * start + alpha * end;
	}
	inline float Clamp(float current, float min, float max)
	{
		min = Min(min, max);
		max = Max(min, max);
		
		if (current > max)
			return max;
		if (current < min)
			return min;
		return current;
	}

	inline float Percent(float current, float min, float max)
	{
		min = Min(min, max);
		max = Max(min, max);
		
		float retVal = current / max;

		return Clamp(retVal, 0, 1);
	}
	
	inline float Cos(float angle) { return cos(angle); }
	inline float Sin(float angle) { return sin(angle); }
	inline float Tan(float angle) { return tan(angle); }
	
	inline float Atan2(float deltaX, float deltaY) { return atan2(deltaX, deltaY); }

	inline float Sqrt(float value) { return sqrt(value); }
	inline float Pow(float value, float pow) { return std::pow(value, pow); }
	inline float Pow2(float value) { Pow(value, 2); }

	namespace Vector {

		template<int Length, typename Type, glm::qualifier qualifier>
		float Distance(
			const glm::vec<Length, Type, qualifier>& lhs,
			const glm::vec<Length, Type, qualifier>& rhs)
		{
			return glm::distance(lhs, rhs);
		}

		template<int Length, typename Type, glm::qualifier qualifier>
		float Dot(
			const glm::vec<Length, Type, qualifier>& lhs,
			const glm::vec<Length, Type, qualifier>& rhs)
		{
			return glm::dot(lhs, rhs);
		}
		template<int Length, typename Type, glm::qualifier qualifier>
		float Cross(
			const glm::vec<Length, Type, qualifier>& lhs,
			const glm::vec<Length, Type, qualifier>& rhs)
		{
			return glm::cross(lhs, rhs);
		}
		template<int Length, typename Type, glm::qualifier qualifier>
		float Normalize(
			const glm::vec<Length, Type, qualifier>& lhs,
			const glm::vec<Length, Type, qualifier>& rhs)
		{
			return glm::cross(lhs, rhs);
		}
	
		
	}
} 
