#pragma once
#include <vector>
#include "Math.h"
namespace OGLE
{
	struct Color
	{
		
		Color(float r, float g, float b, float a = 1.0f)
		{
			this->r = Math::Clamp(r, 0.0f, 255.0f);
			this->g = Math::Clamp(g, 0.0f, 255.0f);
			this->b = Math::Clamp(b, 0.0f, 255.0f);
			this->a = Math::Clamp(a, 0.0f, 1.0f);
		}

		Color(const Vector4& color)
		{
			r = Math::Clamp(color.x, 0.0f, 255.0f);
			g = Math::Clamp(color.y, 0.0f, 255.0f);
			b = Math::Clamp(color.z, 0.0f, 255.0f);
			a = Math::Clamp(color.w, 0.0f, 1.0f);
		}
		
		void SetColor(const float r, const float g, const float b, const float a = 1.0f)
		{
			this->r = Math::Clamp(r, 0.0f, 255.0f);
			this->g = Math::Clamp(g, 0.0f, 255.0f);
			this->b = Math::Clamp(b, 0.0f, 255.0f);
			this->a = Math::Clamp(a, 0.0f, 1.0f);
		}
		void SetRed  (const float r) { this->r = Math::Clamp(r, 0.0f, 255.0f); }
		void SetGreen(const float g) { this->g = Math::Clamp(g, 0.0f, 255.0f); }
		void SetBlue (const float b) { this->b = Math::Clamp(b, 0.0f, 255.0f); }
		void SetAlpha (const float a) { this->b = Math::Clamp(a, 0.0f, 1.0f); }
		
		void Normalize()
		{
			r /= 255;
			g /= 255;
			b /= 255;
		}

		[[nodiscard]] Color Normalized() const
		{
			return Color(r / 255, g / 255, b / 255, a);
		}
		[[nodiscard]] auto R01() const { return r / 255; }
		[[nodiscard]] auto G01() const { return g / 255; }
		[[nodiscard]] auto B01() const { return b / 255; }

		[[nodiscard]] auto R() const { return r; }
		[[nodiscard]] auto G() const { return g; }
		[[nodiscard]] auto B() const { return b; }

		[[nodiscard]] auto A() const { return a; }

		
	
	private:
		float r, g, b, a;
	};
}
