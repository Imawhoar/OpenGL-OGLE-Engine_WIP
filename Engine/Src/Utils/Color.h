#pragma once
#include <vector>
#include "Math.h"
namespace OGLE
{
	class Color
	{
	
	public:
		Color(float r, float g, float b, float a = 1.0f)
		{
			m_color.x = Math::Clamp(r, 0.0f, 255.0f);
			m_color.y = Math::Clamp(g, 0.0f, 255.0f);
			m_color.z = Math::Clamp(b, 0.0f, 255.0f);
			m_color.w = Math::Clamp(a, 0.0f, 1.0f);
		}

		Color(const Vector4& color) : m_color(color){}
		
		void SetColor(float r, float g, float b, float a = 1.0f)
		{
			m_red = Math::Clamp(r, 0.0f, 255.0f);
			m_green = Math::Clamp(g, 0.0f, 255.0f);
			m_blue = Math::Clamp(b, 0.0f, 255.0f);
			m_alpha = Math::Clamp(a, 0.0f, 1.0f);
		}
		
		void SetRed(float value)   { m_color.x   = Math::Clamp(value, 0.0f, 255.0f); }
		void SetGreen(float value) { m_color.y = Math::Clamp(value, 0.0f, 255.0f); }
		void SetBlue(float value)  { m_color.z = Math::Clamp(value, 0.0f, 255.0f); }
		void SetAlpha(float value) { m_color.x = Math::Clamp(value, 0.0f, 1.0f); }

		
		[[nodiscard]] auto GetRed()     const { return m_color.x; }
		[[nodiscard]] auto GetGreen()   const { return m_color.y; }
		[[nodiscard]] auto GetBlue()    const { return m_color.z; }

		[[nodiscard]] auto GetRed01()   const { return m_color.x / 255; }
		[[nodiscard]] auto GetGreen01() const { return m_color.y / 255; }
		[[nodiscard]] auto GetBlue01()  const { return m_color.z / 255; }

		[[nodiscard]] auto GetAlpha()   const { return m_color.w; }

	private:
		Vector4 m_color;

		Color() = default;
	};
}
