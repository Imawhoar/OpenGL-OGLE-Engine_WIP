#include "Core/Input/InputManager.h"
#include <iostream>
#include "Core/Input/InputAction.h"

namespace OGLE
{


	InputManager::InputManager() : m_actionMaps({}) {
		std::cout << ("INITIALIZED INPUT-MANAGER...\n");
	}

	InputManager::~InputManager()
	{
		for (const InputAction* action : m_actionMaps) {
			delete(action);
		}
	}

	InputManager* InputManager::CreateAction(const std::string& name)
	{
		//Probably a better way of doing this
		for (const auto& action : m_actionMaps) {
			if (action->GetName() == name)
				return this;
		}
		m_actionMaps.push_back(new InputAction(name));
		return this;
	}

	InputAction* InputManager::GetAction(const std::string& name, bool createIfNotFound)
	{
		for (auto& action : m_actionMaps) {
			if (action->GetName() == name)
				return action;
		}
		if (createIfNotFound)
		{
			std::cout << ("COULD NOT FIND ACTION: \"{0}\"!\n", name.c_str());
			std::cout << ("CREATING \"{0}\"...\n", name.c_str());
			return CreateAction(name)->GetAction(name);
		}

		std::cout << ("COULD NOT FIND ACTION: \"{0}\"!\n", name.c_str());
		return nullptr;
	}

	void InputManager::Bind(const std::string& name, const std::function<void(float)>& func)
	{
		const auto action = GetAction(name);
		const auto callback = action->GetCallbacks();
		callback->Bind(func);
	}



	void InputManager::AddKey(const std::string& name, const InputPair& pair)
	{
		const auto action = GetAction(name);
		return action->AddKeyEvent(pair);
	}

	void InputManager::PollInputEvent(GLFWwindow* window)
	{
		for (auto& actionMap : m_actionMaps)
		{
			actionMap->Evaluate(window);
			actionMap->Execute();
		}
	}


	void InputManager::AddKey(const std::string& name, const KeyCode& key, float value)
	{
		const auto action = GetAction(name);
		action->AddKeyEvent(key, value);
	}
	void InputManager::AddKey(const std::string& name, const MouseCode& key, float value)
	{
		const auto action = GetAction(name);
		action->AddKeyEvent(key, value);
	}
}
