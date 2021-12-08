#include "Time.h"
namespace OGLE
{
	double Time::GetUnscaledTime() const
	{
		return unscaledTime;
	}

	double Time::GetTime() const
	{
		return time;
	}

	double Time::GetDeltaTime() const
	{
		return deltaTime;
	}

	double Time::GetUnscaledDeltaTime() const
	{
		return unscaledDeltaTime;
	}

	double Time::GetTimeDilation() const
	{
		return timeDilation;
	}

	void Time::SetTimeDialation(double value)
	{
		timeDilation = value;
	}

	void Time::Update()
	{
		unscaledTime = glfwGetTime();
		unscaledDeltaTime = unscaledTime - unscaledLastTime;
		unscaledLastTime = unscaledTime;

		time += timeDilation * glfwGetTime();
		deltaTime = time - lastTime;
		lastTime = time;

	}
}
