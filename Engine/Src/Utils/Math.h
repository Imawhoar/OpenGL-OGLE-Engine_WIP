#pragma once
#include <cmath>

namespace OGLE::Math
{
	template <typename T>
	T Max(T lhs, T rhs) { return lhs > rhs ? lhs : rhs; }

	template <typename T>
	T Min(T lhs, T rhs) { return lhs < rhs ? lhs : rhs; }

	template <typename T>
	T Abs(T value) { return value < 0 ? -value : value; }

	template <typename T>
	T Lerp(T start, T end, T alpha)
	{
		return (1 - alpha) * start + alpha * end;
	}

	template <typename T>
	T Clamp(T current, T min, T max)
	{
		min = Min(min, max);
		max = Max(min, max);

		if (current > max)
			return max;
		if (current < min)
			return min;
		return current;
	}

	template <typename T>
	T ClampRepeat(T current, T min, T max)
	{
		min = Min(min, max);
		max = Max(min, max);
		if (current < min)
			return current = max - current;
		if (current > max)
			return current = min + current;
		return current;
	}

	template <typename T>
	T Percent(T current, T min, T max)
	{
		min = Min(min, max);
		max = Max(min, max);

		const float retVal = current / max;

		return Clamp(retVal, 0.0f, 1.0f);
	}

	template <typename T>
	T Cos(T angle) { return cos(angle); }

	template <typename T>
	T Sin(T angle) { return sin(angle); }

	template <typename T>
	T Tan(T angle) { return tan(angle); }

	template <typename T>
	T Atan2(T deltaX, T deltaY) { return atan2(deltaX, deltaY); }

	template <typename T>
	T Sqrt(T value) { return sqrt(value); }

	template <typename T>
	T Pow(T value, T pow) { return std::pow(value, pow); }

	template <typename T>
	T Pow2(T value) { return Pow(value, 2); }



}
