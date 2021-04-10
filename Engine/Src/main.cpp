#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Core/Application.h"
#include "Core/Camera2D.h"
#include "Core/Renderer.h"
#include "Core/Sprite.h"
#include "Core/Texture.h"

#include "Resources/Shader.h"
#include "Tools/FileHandler.h"


void EngineStuff()
{
	auto resourcePath = OGLE::FileHandler::GetResourcePath();
	auto squarePath = OGLE::FileHandler::FindResource("square.png");
	auto vertexShaderPath = OGLE::FileHandler::FindResource("vertexShader.shader");
	auto fragmentPath = OGLE::FileHandler::FindResource("fragmentShader.shader");


	OGLE::Core::Application application("Game", 1280, 720, 4, 4);
	OGLE::Core::Camera2D cam;

	OGLE::Resources::Shader shader(vertexShaderPath, fragmentPath);
	OGLE::Registry::AssetRegistry<OGLE::Resources::Shader>::Insert("default", &shader);

	OGLE::Core::Texture texture(squarePath);
	OGLE::Registry::AssetRegistry<OGLE::Core::Texture>::Insert("default", &texture);


	OGLE::Core::Sprite sprite(
		OGLE::Registry::AssetRegistry<OGLE::Core::Texture>::Get("default"),
		OGLE::Registry::AssetRegistry<OGLE::Resources::Shader>::Get("default"));

	OGLE::Core::Renderer renderer(&cam);
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