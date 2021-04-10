#pragma once
#include <vector>
#include "Math.h"
namespace OGLE
{
	class Color
	{
	private:
		float m_red;
		float m_green;
		float m_blue;
		float m_alpha;

		Color() = default;
	public:
		Color(float r, float g, float b, float a = 1.0f)
		{
			m_red = Math::Clamp(r, 0.0f, 255.0f);
			m_green = Math::Clamp(g, 0.0f, 255.0f);
			m_blue = Math::Clamp(b, 0.0f, 255.0f);
			m_alpha = Math::Clamp(a, 0.0f, 1.0f);
		}

		
		void SetColor(float r, float g, float b, float a = 1.0f)
		{
			m_red = Math::Clamp(r, 0.0f, 255.0f);
			m_green = Math::Clamp(g, 0.0f, 255.0f);
			m_blue = Math::Clamp(b, 0.0f, 255.0f);
			m_alpha = Math::Clamp(a, 0.0f, 1.0f);
		}
		
		void SetRed(float value)   { m_red   = Math::Clamp(value, 0.0f, 255.0f); }
		void SetGreen(float value) { m_green = Math::Clamp(value, 0.0f, 255.0f); }
		void SetBlue(float value)  { m_blue  = Math::Clamp(value, 0.0f, 255.0f); }

		void SetRed01(float value)   { m_red   = Math::Clamp(value, 0.0f, 1.0f);  }
		void SetGreen01(float value) { m_green = Math::Clamp(value, 0.0f, 1.0f); }
		void SetBlue01(float value)  { m_blue  = Math::Clamp(value, 0.0f, 1.0f); }

		void SetAlpha(float value) { m_alpha = Math::Clamp(value, 0.0f, 1.0f); }

		
		[[nodiscard]] auto GetRed()     const { return m_red; }
		[[nodiscard]] auto GetGreen()   const { return m_green; }
		[[nodiscard]] auto GetBlue()    const { return m_blue; }

		[[nodiscard]] auto GetRed01()   const { return m_red / 255; }
		[[nodiscard]] auto GetGreen01() const { return m_green / 255; }
		[[nodiscard]] auto GetBlue01()  const { return m_blue / 255; }

		[[nodiscard]] auto GetAlpha()   const { return m_alpha; }
	};
}
