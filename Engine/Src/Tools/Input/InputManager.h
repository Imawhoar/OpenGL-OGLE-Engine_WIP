#pragma once
#include <array>
#include <algorithm>
#include <unordered_map>

#include "InputCode.h"

#include "../Template/TCallback.h"
#include "../Template/TPureSingleton.h"
namespace OGLE::Input
{
	struct CallbackContext
	{
		float value;
		std::array<float, 3> vecValue;
	};

	struct InputValuePair
	{
		KeyCode keyCode;
		MouseCode mouseCode;
		float downCounter;
		bool  isDown;
	};
	class InputAction
	{
		enum class KeyType
		{
			Key,
			Mouse
		};
		KeyType type;
		bool isActive;
		CallbackContext context;
		std::vector<InputValuePair> inputList;
	};
	class ActionMap
	{

		std::vector<InputAction> actionMap;
		void Add(const InputAction& action) { actionMap.push_back(action); }
		void Remove(const InputAction& action)
		{
			actionMap.erase(
				std::remove(
					actionMap.begin(), 
					actionMap.end(), 
					action), 
				actionMap.end());
		};
	};


	typedef Template::TCallback<CallbackContext> InputCallback;

	class InputManager : Template::TPureSingleton<InputManager>
	{

	private:

	public:


	};

}
