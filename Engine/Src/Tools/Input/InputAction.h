#pragma once
#include <GLFW/glfw3.h>

#include "InputCode.h"

#include "../Template/Delegate/TCallback.h"

#define CAST(value, type) static_cast<type>(value)

namespace OGLE::Input
{
	typedef Template::TCallback<float> CallbackContext;

	inline static bool KeyDown(GLFWwindow* window, KeyCode key)
	{
		return glfwGetKey(window, CAST(key, int)) == CAST(PressType::Down, int);
	}
	inline static bool KeyUp(GLFWwindow* window, KeyCode key)
	{
		return glfwGetKey(window, CAST(key, int)) == CAST(PressType::Release, int);
	}

	inline static bool MouseDown(GLFWwindow* window, MouseCode mouse)
	{
		return glfwGetMouseButton(window, CAST(mouse, int)) == CAST(PressType::Down, int);
	}
	inline static bool MouseUp(GLFWwindow* window, MouseCode mouse)
	{
		return glfwGetMouseButton(window, CAST(mouse, int)) == CAST(PressType::Release, int);
	}

	struct InputPair
	{
		KeyCode keyCode;
		MouseCode mouseCode;
		float value;
	};
	
	class InputAction
	{
	public:

		InputType inputType;
		PressType pressType;
		bool isActive = true;
		float maxValue = 1;
		CallbackContext context;

	public:
		void Evaluate(GLFWwindow* window)
		{
			if (!isActive || !window)
				return;

			for (auto& pair : m_keyValuePair)
			{

				if (inputType == InputType::Key)
				{
					if (KeyDown(window, pair.keyCode));
					else
					{
					}
				}
				else if (inputType == InputType::Mouse)
				{
					if (MouseDown(window, pair.mouseCode));
				}

			}
		}
		[[nodiscard]] auto& GetValuePair() const { return m_keyValuePair; }
	private:
		std::vector<InputPair> m_keyValuePair{};
	};
}
