#pragma once
#include "GLFW/glfw3.h"
#include <array>
#include <unordered_map>
#include <string>

#include "InputAction.h"

namespace OGLE::Input
{
	typedef std::unordered_map<std::string, InputAction> InputActionMap;

	class InputManager final
	{
	public:

		/**
		 * \brief IMPORTANT! Only use this method outside of the caller class!
		 * TODO: Make this work like intended.
		 */
		template<typename TCaller>
		void Bind(const std::string& actionName, TCaller& caller, void(TCaller::* func)(float)) { m_actionMaps[actionName].GetCallbacks().Bind([&](float x) {(caller.*func)(x); }); }
		void Bind(const std::string& actionName, const std::function<void(float)>& func) { m_actionMaps[actionName].GetCallbacks().Bind(func); }

		template<typename TKey>
		void AddKey(const std::string& actionName, const TKey& key, float value) { m_actionMaps[actionName].AddKeyEvent(key, value); }
		void AddKey(const std::string& actionName, const InputPair& pair) { m_actionMaps[actionName].AddKeyEvent(pair); }
		
		void PollInputEvent(GLFWwindow* window)
		{
			for (auto& actionMap : m_actionMaps)
			{
				actionMap.second.Evaluate(window);
				actionMap.second.Execute();
			}
		}
	private:
		InputActionMap m_actionMaps;
	};

}
