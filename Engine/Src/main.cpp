#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Core/Application.h"
#include "Core/Camera2D.h"
#include "Core/Renderer.h"
#include "Core/Sprite.h"
#include "Core/Image.h"
#include "Core/Shader.h"
#include "Core/Texture.h"

#include "Tools/FileHandler.h"
#include "Tools/SharedAssets.h"

int main() {

	auto resourcePath = FileHandler::GetResourcePath();
	auto squarePath = FileHandler::FindResource("square.png");
	auto vertexShaderPath = FileHandler::FindResource("vertexShader.shader");
	auto fragmentPath = FileHandler::FindResource("fragmentShader.shader");


	Application application("Engine", 1280, 720, 4, 4);
	Camera2D cam;
	Shader shader(vertexShaderPath, fragmentPath);
	Texture texture(squarePath.c_str());
	Sprite sprite(&texture, &shader);
	Renderer renderer(&cam);
	renderer.AddRenderTarget(&sprite);
	/* Loop until the user closes the m_window */
	while (!application.WindowShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.50f, 0.5f, 0.6f, 1.0f);


		renderer.Render();

		glfwSwapBuffers(application.GetWindow());
		glfwPollEvents();
	}


	glfwTerminate();
	return 0;
}