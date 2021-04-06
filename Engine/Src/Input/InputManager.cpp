#include "InputManager.h"


InputManager::InputManager(GLFWwindow* window) {
	m_window = window;
}

bool InputManager::GetKey(KeyCode key) {
	return glfwGetKey(m_window, (int)key);
}