#include "Core/Input/InputAction.h"
#include "Utils/Utils.h"
namespace OGLE
{
	bool KeyDown(GLFWwindow* window, KeyCode key)
	{
		return glfwGetKey(window, static_cast<int>(key)) == static_cast<int>(PressType::Down);
	}

	bool KeyUp(GLFWwindow* window, KeyCode key)
	{
		return glfwGetKey(window, static_cast<int>(key)) == static_cast<int>(PressType::Release);
	}

	bool MouseDown(GLFWwindow* window, MouseCode mouse)
	{
		return glfwGetMouseButton(window, static_cast<int>(mouse)) == static_cast<int>(PressType::Down);
	}

	bool MouseUp(GLFWwindow* window, MouseCode mouse)
	{
		return glfwGetMouseButton(window, static_cast<int>(mouse)) == static_cast<int>(PressType::Release);
	}

	InputAction::InputAction(const InputAction& action) : m_name(action.GetName()), m_inputType(), m_pressType(), m_isActive(true) {
	}

	InputAction::InputAction(std::string name, bool active) : m_name(std::move(name)), m_inputType(), m_pressType(), m_isActive(active) {
	}
	void InputAction::Evaluate(GLFWwindow* window)
	{
		if (!m_isActive || !window)
			return;

		float actionValue = 0;
		for (auto& keyPair : m_keyValuePair)
		{
			if (m_inputType == InputType::Keyboard)
			{
				if (KeyDown(window, keyPair.keyCode))
				{
					actionValue += keyPair.GetValue();
				}
			}
			else if (m_inputType == InputType::Mouse)
			{
				if (MouseDown(window, keyPair.mouseCode))
					actionValue += keyPair.GetValue();
			}
		}
		m_value = Math::Clamp(actionValue, -m_maxValue, m_maxValue);
	}

	void InputAction::Execute()
	{
		m_callbacks.Invoke(m_value);
	}

	void InputAction::AddKeyEvent(const KeyCode& code, float value)
	{
		m_keyValuePair.emplace_back(code, value);
	}

	void InputAction::AddKeyEvent(const MouseCode& code, float value)
	{
		m_keyValuePair.emplace_back(code, value);
	}

	void InputAction::AddKeyEvent(const InputPair& keyPair)
	{
		m_keyValuePair.push_back(keyPair);
	}

	void InputAction::SetPressType(const PressType& pressType)
	{
		m_pressType = pressType;
	}

	void InputAction::SetInputType(const InputType& inputType)
	{
		m_inputType = inputType;
	}

	void InputAction::SetActive(bool active)
	{
		m_isActive = active;
	}

	void InputAction::SetMaxValue(float value)
	{
		m_maxValue = value;
	}

	void InputAction::SetName(const std::string& name)
	{
		m_name = name;
	}



	InputType InputAction::GetInputType() const
	{
		return m_inputType;
	}

	PressType InputAction::GetPressType() const
	{
		return m_pressType;
	}

	bool InputAction::IsIsActive() const
	{
		return m_isActive;
	}

	float InputAction::GetValue() const
	{
		return m_value;
	}

	float InputAction::GetMaxValue() const
	{
		return m_maxValue;
	}

	const std::string& InputAction::GetName() const
	{
		return m_name;
	}

	const std::vector<InputPair>& InputAction::GetKeyValuePair() const
	{
		return m_keyValuePair;
	}
	InputAction::InputCallbackContext* InputAction::GetCallbacks() {
		return &m_callbacks;
	}
}
