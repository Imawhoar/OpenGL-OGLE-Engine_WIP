#pragma once
#include "GLFW/glfw3.h"
#include "Point.h"
namespace OGLE
{
	class Cursor
	{
	public:
		void UpdateMouse(GLFWwindow* window) { glfwGetCursorPos(window, &position.x, &position.y); }

		[[nodiscard]] int  GetCursorX() const { return position.x; }
		[[nodiscard]] int  GetCursorY() const { return position.y; }
		[[nodiscard]] auto GetCursor()  const { return position; }
	private:
		Point<double> position;
	};
}
