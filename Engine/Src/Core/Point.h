#pragma once

namespace OGLE
{
	template<typename T>
	struct Point
	{
		Point() : x(0), y(0){}
		Point(T x, T y) : x(x), y(y){}
		T x;
		T y;
	};
}
