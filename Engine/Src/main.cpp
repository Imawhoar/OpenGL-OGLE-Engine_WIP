#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Core/Application.h"
#include "Core/Camera2D.h"
#include "Core/Renderer.h"
#include "Core/Sprite.h"
#include "Core/Texture.h"

#include "Resources/Shader.h"
#include "Tools/FileHandler.h"
#include "Tools/Template/TRegistry.h"

void EngineStuff()
{
	auto resourcePath = OGLE::FileHandler::GetResourcePath();
	auto squarePath = OGLE::FileHandler::FindResource("square.png");
	auto vertexShaderPath = OGLE::FileHandler::FindResource("vertexShader.shader");
	auto fragmentPath = OGLE::FileHandler::FindResource("fragmentShader.shader");

	
	
	OGLE::Application application("Game", 1280, 720, 4, 4);
	OGLE::Camera2D cam;

	OGLE::Shader shader(vertexShaderPath, fragmentPath);
	OGLE::Registry::AssetRegistry<OGLE::Shader>::Insert("default", &shader);

	OGLE::Texture texture(squarePath);
	OGLE::Registry::AssetRegistry<OGLE::Texture>::Insert("default", &texture);


	OGLE::Sprite sprite(
		OGLE::Registry::AssetRegistry<OGLE::Texture>::Get("default"),
		OGLE::Registry::AssetRegistry<OGLE::Shader>::Get("default"));

	OGLE::Renderer renderer(&cam);
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

}
int main() {
	EngineStuff();
	return 0;
}