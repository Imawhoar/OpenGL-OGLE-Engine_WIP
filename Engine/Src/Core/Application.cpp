#include "Application.h"

#include <iostream>

#include "Application.h"


Application::Application(const char* name, int width, int height, int major, int minor)
	: m_windowName(name), m_screenWidth(width), m_screenHeight(height), m_versionMajor(major), m_versionMinor(minor)
{
	m_screenRatio = (float)m_screenWidth / m_screenHeight;
	InitializeOpenGL();
}


Application::Application(const char* name, int width, int height)
	: m_windowName(name), m_screenWidth(width), m_screenHeight(height), m_versionMajor(4), m_versionMinor(4)
{
	m_screenRatio = (float)m_screenWidth / m_screenHeight;
	InitializeOpenGL();
}

void Application::SetFrameBufferSize(int width, int height) {
	m_screenRatio = (float)width / (float)height;
	glViewport(0, 0, width, height);
}


int Application::InitializeOpenGL() {
	if (!glfwInit())
		return 0;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_versionMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_versionMinor);

	m_window = glfwCreateWindow(m_screenWidth, m_screenHeight, m_windowName, NULL, NULL);

	if (!m_window) {
		glfwTerminate();
		return 0;
	}

	glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		});

	glfwMakeContextCurrent(m_window);
	if (!gladLoadGL()) {
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return 0;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return 1;
}

GLFWwindow* Application::GetWindow() {
	return m_window;
}