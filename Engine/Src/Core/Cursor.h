#pragma once
#include "oglepch.h"
#include "Input/Point.h"
namespace OGLE
{
	class Cursor
	{
	public:
		void Update(GLFWwindow* window)
		{
			glfwGetCursorPos(window, &position.x, &position.y);
			delta = position - oldPosition;
			oldPosition = position;
		}

		[[nodiscard]] auto GetCursorX() const { return position.x; }
		[[nodiscard]] auto GetCursorY() const { return position.y; }
		[[nodiscard]] auto GetCursor()  const { return position; }

		[[nodiscard]] auto GetDeltaX() const { return delta.x; }
		[[nodiscard]] auto GetDeltaY() const { return delta.y; }
		[[nodiscard]] auto GetDelta()  const { return delta; }

	private:
		Point<double> position;
		Point<double> oldPosition;
		Point<double> delta;
	};
}
