#pragma once

namespace OGLE
{
	template<typename T>
	struct Point
	{
		Point() : x(0), y(0) {}
		Point(T x, T y) : x(x), y(y) {}
		T x;
		T y;

		Point operator +(const Point& rhs) { return Point(x + rhs.x, y + rhs.y); }
		Point operator -(const Point& rhs) { return Point(x - rhs.x, y - rhs.y); }
		Point operator *(const Point& rhs) { return Point(x * rhs.x, y * rhs.y); }
		Point operator /(const Point& rhs) { return Point(x / rhs.x, y / rhs.y); }
		Point operator *(T rhs)			   { return Point(x * rhs,   y * rhs); }
		Point operator /(T rhs)			   { return Point(x / rhs,   y / rhs); }
	};
}
