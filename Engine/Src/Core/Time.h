#pragma once
#include "GLFW/glfw3.h"

namespace OGLE
{
	class Time {
		double unscaledTime = 0;
		double time = 0;

		double deltaTime = 0;
		double unscaledDeltaTime = 0;

		double timeDilation = 1;
		double lastTime = 0;
		double unscaledLastTime = 0;
	public:
		double GetUnscaledTime() const;
		double GetTime() const;
		double GetDeltaTime() const;
		double GetUnscaledDeltaTime() const;

		double GetTimeDilation() const;
		void SetTimeDialation(double value);

		void Update();
	};
}
