#pragma once
#include "GLFW/glfw3.h"
#include <string>
#include "InputAction.h"


namespace OGLE::Input
{
	class InputManager final
	{
	public:
		InputManager()
		{
			m_actionMaps = {};
			std::cout << ("INITIALIZED INPUT-MANAGER...");
		}
		InputManager* CreateAction(const std::string& name)
		{
			//Probably a better way of doing this
			for (const auto& action : m_actionMaps) {
				if (action.GetName() == name)
					return this;
			}
			m_actionMaps.emplace_back(name);
			return this;
		}
		[[nodiscard]] InputAction* GetAction(const std::string& name, bool createIfnFnd = false)
		{
			for (auto& action : m_actionMaps) {
				if (action.GetName() == name)
					return &action;
			}
			if (createIfnFnd)
			{
				std::cout << ("COULD NOT FIND ACTION: \"{0}\"!", name.c_str());
				std::cout << ("CREATING \"{0}\"...", name.c_str());
				CreateAction(name);
				return GetAction(name);
			}

			std::cout << ("COULD NOT FIND ACTION: \"{0}\"!", name.c_str());
			return nullptr;
		}

		/**
		 * \brief IMPORTANT! Only use this method outside of the caller class!
		 * TODO: Make this work like intended.
		 */
		template<typename TCaller>
		void Bind(const std::string& name, TCaller& caller, void(TCaller::* func)(float)) { GetAction(name)->GetCallbacks().Bind([&](float x) {(caller.*func)(x); }); }
		void Bind(const std::string& name, const std::function<void(float)>& func) { GetAction(name)->GetCallbacks().Bind(func); }

		template<typename TKey>
		void AddKey(const std::string& name, const TKey& key, float value) { GetAction(name)->AddKeyEvent(key, value); }
		void AddKey(const std::string& name, const InputPair& pair) { GetAction(name)->AddKeyEvent(pair); }

		void PollInputEvent(GLFWwindow* window)
		{
			for (auto& actionMap : m_actionMaps)
			{
				actionMap.Evaluate(window);
				actionMap.Execute();
			}
		}
	private:
		std::vector<InputAction> m_actionMaps;
	};

}
