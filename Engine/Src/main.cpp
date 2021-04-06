#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <vector>

#include "Input/InputManager.h"


#include "core/Application.h"
#include "core/Shader.h"
#include "core/Image.h"
#include "core/Texture.h"
#include "core/Sprite.h"
#include "core/Camera2D.h"
#include "core/Renderer.h"
#include "core/Time.h"

#include "Tools/FileHandler.h"


int main() {

	
	Application m_application("Test App", 1280, 720, 4, 4);

	auto resourcePath = FileHandler::GetResourcePath();

	auto temp = FileHandler::FindFilePath(resourcePath, "square.png");
	Image image("C:/Users/salar/Documents/Programming/C++/dev/OpenGL_2DEngine/Engine/Resources/Images/square.png");
	
	Texture texture(&image);
	//Shader shader(FileHandler::FindFilePath("fragmentShader.shader").c_str(), FileHandler::FindFilePath("vertexShader.shader").c_str());
	Shader shader(
		"C:/Users/salar/Documents/Programming/C++/dev/OpenGL_2DEngine/Engine/Resources/Shaders/vertexShader.shader",
		"C:/Users/salar/Documents/Programming/C++/dev/OpenGL_2DEngine/Engine/Resources/Shaders/fragmentShader.shader");
	Sprite sprite(&texture, &shader);

	Camera2D m_camera(0.01f, 1000.0f);
	

	Renderer m_renderer(&m_camera);
	m_renderer.AddRenderTarget(&sprite);
	InputManager m_input(m_application.GetWindow());
	Time m_time;

	while (!m_application.WindowShouldClose()) {

		m_time.UpdateTime();

		glClearColor(0.5f, 0.6f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		sprite.GetTransform().AddPosition(glm::vec3(1.0f * m_time.deltaTime, 0, 0));

		sprite.bind();
		sprite.draw();

		glfwSwapBuffers(m_application.GetWindow());
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}