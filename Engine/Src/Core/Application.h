#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

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
	int InitializeOpenGL();

public:
	Application(const char* name, int width, int height);
	Application(const char* name, int width, int height, int major, int minor);

public:
	void SetFrameBufferSize(int width, int height);
	bool WindowShouldClose() {
		return glfwWindowShouldClose(m_window);
	}
	GLFWwindow* GetWindow();
};

