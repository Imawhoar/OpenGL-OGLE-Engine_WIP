#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Core/Application.h"
#include "Core/Camera2D.h"
#include "Core/Renderer.h"
#include "Core/Sprite.h"
#include "Core/Texture.h"

#include "Resources/Shader.h"

#include "Tools/TRegistry.h"
#include "Tools/FileHandler.h"
#include "Tools/Event/TDelegate.h"


void EngineStuff()
{
	auto resourcePath = FileHandler::GetResourcePath();
	auto squarePath = FileHandler::FindResource("square.png");
	auto vertexShaderPath = FileHandler::FindResource("vertexShader.shader");
	auto fragmentPath = FileHandler::FindResource("fragmentShader.shader");


	Application application("Engine", 1280, 720, 4, 4);
	Camera2D cam;

	Shader shader(vertexShaderPath, fragmentPath);
	AssetRegistry<Shader>::Instance().Insert("default", &shader);

	Texture texture(squarePath);
	AssetRegistry<Texture>::Instance().Insert("default", &texture);


	Sprite sprite(
		AssetRegistry<Texture>::Instance().Get("default"),
		AssetRegistry<Shader>::Instance().Get("default"));

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
}



struct some_struct {
	int x;
	void some_function(float x)
	{
		std::cout << x << std::endl;
	}
};

int main() {

	some_struct first, second, last;
	second.x = 2;
	first.x = 1;
	TDelegate<void, float> temp;

	//temp.Bind(&some_struct::some_function, &first);

	temp.Bind([&](float x)
	{
			first.some_function(x);
	});
	
	temp.Invoke(2.0f);
	std::cin.get();
}