#pragma once
#include "InputAction.h"
namespace OGLE::Input
{

	class InputProfile
	{
	public:
		const auto& Get(const std::string& key) { return m_actions[key]; }
		void Create(const std::string& key) { m_actions[key] = InputAction(); }
		void Insert(const std::string& key, const InputAction& value) { m_actions[key] = value; }
		void Remove(const std::string& key) { m_actions.erase(key); }

		
		void Evaluate(GLFWwindow* window)
		{
			for (auto& action: m_actions)
			{
				action.second.Evaluate(window);
				
			}
		}
	private:
		std::unordered_map<std::string, InputAction> m_actions;
	};
}
