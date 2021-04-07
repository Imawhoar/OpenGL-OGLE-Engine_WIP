#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Core/Application.h"
#include "Core/Camera2D.h"
#include "Core/Renderer.h"
#include "Core/Sprite.h"
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
	SharedAsset<Shader>::Instance().Insert("default", &shader);

	Texture texture(squarePath);
	SharedAsset<Texture>::Instance().Insert("default", &texture);

	
	Sprite sprite(
		SharedAsset<Texture>::Instance().Get("default"), 
		SharedAsset<Shader>::Instance().Get("default"));
	
	Renderer renderer(&cam);
	renderer.AddRenderTarget(&sprite);

	
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