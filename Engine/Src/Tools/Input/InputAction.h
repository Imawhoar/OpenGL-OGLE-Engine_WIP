#pragma once
#include <GLFW/glfw3.h>

#include "InputCode.h"

#include "../Template/Delegate/TCallback.h"

#define CAST(value, type) static_cast<type>(value)

namespace OGLE::Input
{
	typedef std::function<void(float)> ActionCallBack;
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
		InputPair(const KeyCode& keyBtn, float value) : keyCode(keyBtn), mouseCode(), value(value){}
		InputPair(const MouseCode& mouseBtn, float value) : keyCode(), mouseCode(mouseBtn), value(value){}
		KeyCode keyCode;
		MouseCode mouseCode;
		float value;
	};

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
						m_value += keyPair.value;
				}
				else if (m_inputType == InputType::Mouse)
				{
					if (MouseDown(window, keyPair.mouseCode))
						m_value += keyPair.value;
				}
			}
			m_value = Math::Clamp(m_value, -m_maxValue, m_maxValue);
		}
		void InvokeEvents()
		{
			for (auto& invokeEvent : m_callbacks)
			{
				invokeEvent(m_value);
			}
		}
		void BindAction(const ActionCallBack& callback)
		{
			m_callbacks.push_back(callback);
		}

		template<typename T>
		void AddKeyEvent(const T code, float value)   { m_keyValuePair.push_back(InputPair(code, value)); }
		template<typename T>
		void AddKeyEvent(const InputPair& keyPair)    { m_keyValuePair.push_back(keyPair); }

		void SetPressType(const PressType& pressType) { m_pressType = pressType; }
		void SetInputType(const InputType& inputType) { m_inputType = inputType; }

		void SetActive(bool active)					  { m_isActive = active; }
		void SetMaxValue(float value)				  { m_isActive = value; }

		[[nodiscard]] auto& GetValuePairs() const { return m_keyValuePair; }
		[[nodiscard]] auto& GetCallbacks() const { return m_callbacks; }

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

		std::vector<ActionCallBack> m_callbacks{};
		std::vector<InputPair> m_keyValuePair{};
	};
}
