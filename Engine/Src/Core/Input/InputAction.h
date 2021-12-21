#pragma once

#include "oepch.h"
#include "InputCode.h"
#include "Tools/Template/TDelegate.h"

namespace OGLE
{

	bool KeyDown(GLFWwindow* window, KeyCode key);
	bool KeyUp(GLFWwindow* window, KeyCode key);

	bool MouseDown(GLFWwindow* window, MouseCode mouse);
	bool MouseUp(GLFWwindow* window, MouseCode mouse);

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

	class InputAction
	{
		OGLE_CALLBACK(float) InputCallbackContext;

	private:
		std::string m_name;

		InputCallbackContext m_callbacks{};
	public:

	private:
		std::vector<InputPair> m_keyValuePair{};
		InputType m_inputType;
		PressType m_pressType;

		bool  m_isActive;
		float m_value = 0;
		float m_maxValue = 1;

	public:
		InputAction(const InputAction& action);
		InputAction(std::string name, bool active = true);
	public:
		void Evaluate(GLFWwindow* window);
		void Execute();

		void AddKeyEvent(const KeyCode& code, float value);
		void AddKeyEvent(const MouseCode& code, float value);
		void AddKeyEvent(const InputPair& keyPair);

		void SetPressType(const PressType& pressType);
		void SetInputType(const InputType& inputType);

		void SetActive(bool active);
		void SetMaxValue(float value);

		void SetName(const std::string& name);

		[[nodiscard]] InputType GetInputType() const;
		[[nodiscard]] PressType GetPressType() const;
		[[nodiscard]] bool IsIsActive() const;
		[[nodiscard]] float GetValue() const;
		[[nodiscard]] float GetMaxValue() const;
		[[nodiscard]] const std::string& GetName() const;
		[[nodiscard]] const std::vector<InputPair>& GetKeyValuePair() const;
		[[nodiscard]] InputCallbackContext* GetCallbacks();


	};


}
