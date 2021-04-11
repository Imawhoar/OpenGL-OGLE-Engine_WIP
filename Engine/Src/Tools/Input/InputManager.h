#pragma once
#include "GLFW/glfw3.h"
#include <array>
#include <unordered_map>
#include <string>
#include "../../OGLE.h"

#include "InputProfile.h"


namespace OGLE::Input
{

	class InputManager : public Template::TPureSingleton<InputManager>
	{

	private:
		std::unordered_map<std::string, InputProfile> m_actionMaps;
		GLFWwindow* currentContext;
	public:
		
		const auto& Get(const std::string& key)		   { return m_actionMaps[key]; }
		
		void Create(const std::string& key)							   { m_actionMaps[key] = InputProfile(); }
		void Insert(const std::string& key, const InputProfile& value) { m_actionMaps[key] = value; }
		void Remove(const std::string& key)							   { m_actionMaps.erase(key); }
		
		void PollInput()
		{
			for (auto& actionMap: m_actionMaps)
			{

			}
		}

	};

}
