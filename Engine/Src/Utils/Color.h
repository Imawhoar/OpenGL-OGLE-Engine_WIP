#pragma once
#include <vector>

namespace OGLE
{
	class Color
	{
	private:
		float m_red;
		float m_green;
		float m_blue;
		float m_alpha;

	public:
		Color(float r, float g, float b);
		Color(float r, float g, float b, float a);
		Color() = delete;

		float GetRed()   const { return m_red; }
		float GetGreen() const { return m_green; }
		float GetBlue()  const { return m_blue; }
		float GetAlpha() const { return m_alpha; }

		float GetRed01()   const { return m_red / 255; }
		float GetGreen01() const { return m_green / 255; }
		float GetBlue01()  const { return m_blue / 255; }
		float GetAlpha01() const { return m_alpha / 255; }
	};
}
