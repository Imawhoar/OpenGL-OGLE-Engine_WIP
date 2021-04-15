#pragma once
#include <GLFW/glfw3.h>

#include "InputCode.h"
#include "Utils/Math.h"
#include "Tools/Template/Delegate/TDelegate.h"

//Put this in a designated class for macros
template<typename TType, typename TTVal>
constexpr TType SCast(TTVal value) { return static_cast<TType>(value); }

namespace OGLE::Input
{
	static bool KeyDown(GLFWwindow* window, KeyCode key) { return glfwGetKey(window, SCast<int>(key)) == SCast<int>(PressType::Down); }
	static bool KeyUp(GLFWwindow* window, KeyCode key) { return glfwGetKey(window, SCast<int>(key)) == SCast<int>(PressType::Release); }

	static bool MouseDown(GLFWwindow* window, MouseCode mouse) { return glfwGetMouseButton(window, SCast<int>(mouse)) == SCast<int>(PressType::Down); }
	static bool MouseUp(GLFWwindow* window, MouseCode mouse) { return glfwGetMouseButton(window, SCast<int>(mouse)) == SCast<int>(PressType::Release); }

	struct InputPair
	{
		InputPair(const KeyCode& keyBtn, float value) : keyCode(keyBtn), mouseCode(), value(value) {}
		InputPair(const MouseCode& mouseBtn, float value) : keyCode(), mouseCode(mouseBtn), value(value) {}
		KeyCode keyCode;
		MouseCode mouseCode;

		auto SetValue(const float value) { this->value = value; }
		[[nodiscard]] auto GetValue() const { return value; }
	private:
		float value;
	};


	OGLE_DELEGATE(void, float) InputCallbackContext;

	class InputAction
	{
	

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
		void AddKeyEvent(const InputPair& keyPair) { m_keyValuePair.push_back(keyPair); }

		void SetPressType(const PressType& pressType) { m_pressType = pressType; }
		void SetInputType(const InputType& inputType) { m_inputType = inputType; }

		void SetActive(bool active) { m_isActive = active; }
		void SetMaxValue(float value) { m_maxValue = value; }

		void SetName(const std::string& name) { m_name = name; }


		[[nodiscard]] auto& GetName() const  { return m_name; }
		[[nodiscard]] auto& GetValuePairs()  { return m_keyValuePair; }
		[[nodiscard]] auto& GetCallbacks()  { return m_callbacks; }

		[[nodiscard]] auto& GetPressType()  { return m_pressType; }
		[[nodiscard]] auto& GetInputType()  { return m_inputType; }

		[[nodiscard]] auto GetActive() const { return m_isActive; }
		[[nodiscard]] auto GetValue() const { return m_value; }
	
	public:
		InputAction(const InputAction& action) : m_inputType(), m_pressType(), m_isActive(true) { m_name = action.GetName(); };
		InputAction(const std::string name, bool active = true) : m_name(name), m_inputType(), m_pressType(), m_isActive(active) {}
	private:

		InputType m_inputType;
		PressType m_pressType;

		bool  m_isActive;
		float m_value = 0;
		float m_maxValue = 1;

		std::string m_name;

		InputCallbackContext m_callbacks{};
		std::vector<InputPair> m_keyValuePair{};
	};


}
