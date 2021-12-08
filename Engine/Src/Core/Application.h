#pragma once

#include "Input/InputManager.h"
#include "Renderer/Renderer.h"
#include "World/World.h"

namespace OGLE
{

	struct WindowsData
	{
		int versionMajor{};
		int versionMinor{};

		GLFWwindow* context = nullptr;

		std::string windowName{};
		unsigned int screenWidth{};
		unsigned int screenHeight{};

		[[nodiscard]] bool WindowShouldClose() const;
		[[nodiscard]] bool Initialize();
		[[nodiscard]] float GetWindowAspectRatio() const;
	};



	class OGLEGame {

	private:
		WindowsData m_window;
		InputManager m_inputManager;
		World m_world;
		//TODO: Renderer should probably not be here
		Renderer m_renderer{};
	public:
		OGLEGame(std::string name, int width, int height, int major = 4, int minor = 4);
		bool Initialize();
		explicit OGLEGame(int major = 4, int minor = 4);

	public:
		void Run();
	};

}
