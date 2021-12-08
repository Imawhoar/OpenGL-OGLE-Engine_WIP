#include "Color.h"
#include "Math.h"

namespace OGLE
{
	float Color::GetR() const
	{
		return r;
	}

	float Color::GetG() const
	{
		return g;
	}

	float Color::GetB() const
	{
		return b;
	}

	float Color::GetA() const
	{
		return a;
	}

	Color::Color(float r, float g, float b, float a) : r(Math::Clamp(r, 0.0f, 255.0f)), g(Math::Clamp(g, 0.0f, 255.0f)),
		b(Math::Clamp(b, 0.0f, 255.0f)), a(Math::Clamp(a, 0.0f, 1.0f))
	{
	}

	Color::Color(const Vector4& color) : r(Math::Clamp(color.x, 0.0f, 255.0f)), g(Math::Clamp(color.y, 0.0f, 255.0f)),
		b(Math::Clamp(color.z, 0.0f, 255.0f)), a(Math::Clamp(color.w, 0.0f, 1.0f))
	{
	}

	void Color::SetColor(float r, float g, float b, float a)
	{
		this->r = Math::Clamp(r, 0.0f, 255.0f);
		this->g = Math::Clamp(g, 0.0f, 255.0f);
		this->b = Math::Clamp(b, 0.0f, 255.0f);
		this->a = Math::Clamp(a, 0.0f, 1.0f);
	}

	void Color::SetRed(float r)
	{
		this->r = Math::Clamp(r, 0.0f, 255.0f);
	}

	void Color::SetGreen(float g)
	{
		this->g = Math::Clamp(g, 0.0f, 255.0f);
	}

	void Color::SetBlue(float b)
	{
		this->b = Math::Clamp(b, 0.0f, 255.0f);
	}

	void Color::SetAlpha(float a)
	{
		this->b = Math::Clamp(a, 0.0f, 1.0f);
	}

	void Color::Normalize()
	{
		r /= 255;
		g /= 255;
		b /= 255;
	}

	Color Color::Normalized() const
	{
		return { r / 255, g / 255, b / 255, a };
	}

	float Color::R01() const
	{
		return r / 255;
	}

	float Color::G01() const
	{
		return g / 255;
	}

	float Color::B01() const
	{
		return b / 255;
	}


}
