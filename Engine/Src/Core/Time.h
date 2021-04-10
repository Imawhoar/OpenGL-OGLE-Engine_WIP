#pragma once
#include <GLFW/glfw3.h>

namespace OGLE
{
	struct Time {
		float time = 0;
		float lastTime = 0;
		float deltaTime = 0;

		void UpdateTime() {
			time = glfwGetTime();
			deltaTime = time - lastTime;
			lastTime = time;
		}
	};
}
