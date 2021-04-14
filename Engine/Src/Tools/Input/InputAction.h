#pragma once
#include <GLFW/glfw3.h>

#include "InputCode.h"
#include "Utils/Math.h"
#include "Tools/Template/Delegate/TDelegate.h"

//Put this in a designated class for macros
#define CAST(value, type) static_cast<type>(value)

namespace OGLE::Input
{
	static bool KeyDown(GLFWwindow* window, KeyCode key) { return glfwGetKey(window, CAST(key, int)) == CAST(PressType::Down, int); }
	static bool KeyUp(GLFWwindow* window, KeyCode key) { return glfwGetKey(window, CAST(key, int)) == CAST(PressType::Release, int); }

	static bool MouseDown(GLFWwindow* window, MouseCode mouse) { return glfwGetMouseButton(window, CAST(mouse, int)) == CAST(PressType::Down, int); }
	static bool MouseUp(GLFWwindow* window, MouseCode mouse) { return glfwGetMouseButton(window, CAST(mouse, int)) == CAST(PressType::Release, int); }

	struct InputPair
	{
		InputPair(const KeyCode& keyBtn, float value) : keyCode(keyBtn), mouseCode(), value(value) {}
		InputPair(const MouseCode& mouseBtn, float value) : keyCode(), mouseCode(mouseBtn), value(value) {}
		KeyCode keyCode;
		MouseCode mouseCode;
		
		void SetValue(float value) { this->value = value; }
		auto GetValue() const { return value; }
	private:
		float value;
	};


	OGLE_MAKE_DELEGATE(void, float) InputCallbackContext;

	class InputAction
	{
	public:
		InputAction(bool active = true) : m_inputType(), m_pressType(), m_isActive(active) {}
	public:
		void Evaluate(GLFWwindow* window)
		{
			if (!m_isActive || !window)
				return;

			m_value = 0;
			for (auto& keyPair : m_keyValuePair)
			{
				if (m_inputType == InputType::Keyboard)
				{
					if (KeyDown(window, keyPair.keyCode))
					{
						m_value += keyPair.GetValue();
					}
				}
				else if (m_inputType == InputType::Mouse)
				{
					if (MouseDown(window, keyPair.mouseCode))
						m_value += keyPair.GetValue();
				}
			}
			m_value = Math::Clamp(m_value, -m_maxValue, m_maxValue);
		}
		void Execute() { m_callbacks.Invoke(m_value); }

		template<typename T>
		void AddKeyEvent(const T code, float value) { m_keyValuePair.push_back(InputPair(code, value)); }
		void AddKeyEvent(const InputPair& keyPair)  { m_keyValuePair.push_back(keyPair); }

		void SetPressType(const PressType& pressType) { m_pressType = pressType; }
		void SetInputType(const InputType& inputType) { m_inputType = inputType; }

		void SetActive  (bool active) { m_isActive = active; }
		void SetMaxValue(float value) { m_maxValue = value;  }

		[[nodiscard]] auto& GetValuePairs()  { return m_keyValuePair; }
		[[nodiscard]] auto& GetCallbacks() { return m_callbacks;    }

		[[nodiscard]] auto& GetPressType() const { return m_pressType; }
		[[nodiscard]] auto& GetInputType() const { return m_inputType; }

		[[nodiscard]] auto GetActive() const { return m_isActive; }
		[[nodiscard]] auto GetValue() const { return m_value; }
	private:

		InputType m_inputType;
		PressType m_pressType;

		bool  m_isActive;
		float m_value = 0;
		float m_maxValue = 1;

		InputCallbackContext m_callbacks{};
		std::vector<InputPair> m_keyValuePair{};
	};
}
