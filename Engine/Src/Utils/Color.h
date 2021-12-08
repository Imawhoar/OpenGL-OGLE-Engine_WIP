#pragma once
#include "Vector.h"

namespace OGLE
{
	class Color
	{
	private:
		float r, g, b, a;
	public:
		Color(float r, float g, float b, float a = 1.0f);
		explicit Color(const Vector4& color);
	public:
		void SetColor(float r, float g, float b, float a = 1.0f);
		void SetRed(float r);
		void SetGreen(float g);
		void SetBlue(float b);
		void SetAlpha(float a);

		void Normalize();

		[[nodiscard]] Color Normalized() const;
		[[nodiscard]] float R01() const;
		[[nodiscard]] float G01() const;
		[[nodiscard]] float B01() const;

		[[nodiscard]] float GetR() const;
		[[nodiscard]] float GetG() const;
		[[nodiscard]] float GetB() const;
		[[nodiscard]] float GetA() const;

	};
}
