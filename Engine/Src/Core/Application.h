#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Debug/Logger.h"
#include <iostream>

namespace OGLE
{

	class Application {

	private:
		GLFWwindow* m_window = nullptr;
		const char* m_windowName{};

		int m_versionMajor{};
		int m_versionMinor{};

		unsigned int m_screenWidth{};
		unsigned int m_screenHeight{};
		float m_screenRatio{};
	private:
		bool InitializeOpenGL() {
			if (!glfwInit()) {
				ENGINE_LOG_CRITICAL("FAILED TO INITIALIZE GLFW!");
				return false;
			}
			ENGINE_LOG_INFO("INITIALIZED OPENGL...");

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_versionMajor);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_versionMinor);

			m_window = glfwCreateWindow(m_screenWidth, m_screenHeight, m_windowName, nullptr, nullptr);

			if (!m_window) {
				ENGINE_LOG_CRITICAL("FAILED TO INITIALIZE WINDOW!");
				glfwTerminate();
				return false;
			}
			ENGINE_LOG_INFO("INITIALIZED WINDOW...");

			glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
				{
					glViewport(0, 0, width, height);
				});

			glfwMakeContextCurrent(m_window);
			if (!gladLoadGL()) {
				ENGINE_LOG_CRITICAL("FAILED TO INITIALIZE OPENGL!");
				return false;
			}
			ENGINE_LOG_INFO("INITIALIZED OPENGL...");

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			
			ENGINE_LOG_INFO("INITIALIZED APPLICATION...");
			return true;
		}


	public:
		Application(const char* name, int width, int height)
			: m_windowName(name), m_screenWidth(width), m_screenHeight(height), m_versionMajor(4), m_versionMinor(4)
		{
			m_screenRatio = static_cast<float>(m_screenWidth) / m_screenHeight;
			InitializeOpenGL();
		}
		Application(const char* name, int width, int height, int major, int minor)
			: m_windowName(name), m_screenWidth(width), m_screenHeight(height), m_versionMajor(major), m_versionMinor(minor)
		{
			m_screenRatio = static_cast<float>(m_screenWidth) / m_screenHeight;
			InitializeOpenGL();
		}

	public:
		void SetFrameBufferSize(float width, float height) {
			m_screenRatio = width/height;
			glViewport(0, 0, width, height);
		}

		[[nodiscard]] auto WindowShouldClose() const { return glfwWindowShouldClose(m_window); }
		[[nodiscard]] auto* GetWindow() const { return m_window; }
	};

}
