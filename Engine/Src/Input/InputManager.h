#pragma once
#include "InputCode.h"
#include "GLFW/glfw3.h"

class InputManager {
private:
	GLFWwindow* m_window;
	InputManager() = delete;
public:
	explicit InputManager(GLFWwindow* window);

public:
	bool GetKey(KeyCode key);

};

