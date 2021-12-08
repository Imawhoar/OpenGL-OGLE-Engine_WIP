#pragma once

#include "OEPCH.h"
#include <string>
#include <functional>
#include "InputAction.h"


namespace OGLE
{


	class InputManager final
	{


	private:
		std::vector<InputAction*> m_actionMaps;
	public:
		InputManager();
		~InputManager();
		InputManager* CreateAction(const std::string& name);


		template<typename TCaller>
		void Bind(const std::string& name, TCaller& caller, void(TCaller::* func)(float)) {
			GetAction(name)->GetCallbacks()->Bind(caller, func);
		}
		void Bind(const std::string& name, const std::function<void(float)>& func);

		void AddKey(const std::string& name, const MouseCode& key, float value);
		void AddKey(const std::string& name, const KeyCode& key, float value);
		void AddKey(const std::string& name, const InputPair& pair);

		void PollInputEvent(GLFWwindow* window);

		[[nodiscard]] InputAction* GetAction(const std::string& name, bool createIfNotFound = true);
	};


}
