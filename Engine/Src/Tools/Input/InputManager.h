#pragma once
#include "GLFW/glfw3.h"
#include <array>
#include <algorithm>
#include <unordered_map>

#include "InputCode.h"

#include "../Template/TCallback.h"
#include "../Template/TPureSingleton.h"
namespace OGLE::Input
{

	typedef Template::TCallback<float> CallbackContext;

	struct InputValuePair
	{
		KeyCode keyCode;
		MouseCode mouseCode;
		float value;
	};
	class InputAction
	{
	public:
		enum class KeyType
		{
			Key,
			Mouse
		};
		KeyType type = KeyType::Key;
		bool isActive = true;

		[[nodiscard]] auto& GetValuePair() const { return m_keyValuePair; }
	private:
		std::vector<InputValuePair> m_keyValuePair;
	};
	class ActionMap
	{
	public:
		void Add(const InputAction& action) { m_actionMap.push_back(action); }
		/*
		void Remove(const InputAction& action)
		{
			m_actionMap.erase(
				std::remove(
					m_actionMap.begin(),
					m_actionMap.end(),
					action),
				m_actionMap.end());
		};
		*/
		CallbackContext context;

		[[nodiscard]] auto& GetMap() const { return m_actionMap; }

	private:
		std::vector<InputAction> m_actionMap;

	};



	class InputManager
	{

	private:
		std::unordered_map<std::string, ActionMap> m_actionMaps;

	public:
		void PollInput()
		{
			for (auto& action : m_actionMaps)
			{
				for (const auto& inputAction : action.second.GetMap())
				{
					for (const auto& valuePair: inputAction.GetValuePair())
					{
						if (!inputAction.isActive)
							break;
						
					}
					
				}
			}
		}
	};

}
