#include "Core/Application.h"
#include "oepch.h"

#include <iostream>

namespace OGLE
{
	bool WindowsData::WindowShouldClose() const
	{
		return glfwWindowShouldClose(context);
	}
	bool WindowsData::Initialize()
	{

		//INITIALIZE GLFW
		//Exit out of the program if GLFW failed to init.
		if (!glfwInit()) {
			std::cout << "FAILED TO INITIALIZE GLFW!\n";
			return false;
		}
		std::cout << ("OPENGL INITIALIZED...\n");

		//What version of OpenGL are we using?
		//MAJOR and MINOR could be 4 and 2 and that would be equal to version 4.2
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);

		//Make sure the player cannot resize the window
		//TODO: Figure out if it's worth letting the user resize.
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		//This is going to be the handle to the actual GAME/WINDOW of the program
		context = glfwCreateWindow(screenWidth, screenHeight, windowName.c_str(), nullptr, nullptr);

		//If the creation of this window failed, we exit.
		if (!context) {
			std::cout << ("FAILED TO INITIALIZE") + windowName + "!\n";
			glfwTerminate();
			return false;
		}
		std::cout << windowName + ("-Window INITIALIZED...\n");

		glfwMakeContextCurrent(this->context);

		//Load OpenGL. If the loading fails, we exit.
		if (!gladLoadGL()) {
			std::cout << ("FAILED TO INITIALIZE OPENGL!\n");
			return false;
		}
		std::cout << ("OPENGL INITIALIZED...\n");

		std::cout << ("APPLICATION INITIALIZED...\n");

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return true;
	}
	float WindowsData::GetWindowAspectRatio() const
	{
		return static_cast<float>(screenWidth) / screenHeight;
	}

	bool OGLEGame::Initialize()
	{
		if (!m_window.Initialize())
			return false;
		if (!m_world.Initialize())
			return false;

		return true;
	}

	OGLEGame::OGLEGame(std::string name, int width, int height, int major, int minor) : m_world()
	{
		m_window.windowName = name;
		m_window.screenWidth = width;
		m_window.screenHeight = height;
		m_window.versionMajor = major;
		m_window.versionMinor = minor;
	}

	OGLEGame::OGLEGame(int major, int minor)
	{
		m_window.windowName = "OGLE WINDOW";
		m_window.screenWidth = 1280;
		m_window.screenHeight = 720;
		m_window.versionMajor = major;
		m_window.versionMinor = minor;
	}

	void OGLEGame::Run()
	{
		if (!Initialize()) {
			std::cout << "Could not initialize OGLE\n";
			return;
		}
		while (!m_window.WindowShouldClose()) {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(m_window.context);
			glfwPollEvents();
			m_world.Tick();
			m_renderer.Render();
		}
	}
}
