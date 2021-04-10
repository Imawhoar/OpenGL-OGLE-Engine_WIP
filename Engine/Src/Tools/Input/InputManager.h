#pragma once
#include <unordered_map>

#include "../Template/TCallback.h"
#include "../Template/TPureSingleton.h"

namespace OGLE::Input
{
	struct CallbackContext
	{

	};

	typedef std::unordered_map<std::string, Template::TCallback<CallbackContext>> EventMap;

	class InputManager : Template::TPureSingleton<InputManager>
	{
		EventMap m_keyEvents;

	public:


	};

}
