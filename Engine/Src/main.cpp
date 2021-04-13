#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "OGLE.h"
using namespace OGLE;

void EngineStuff()
{
	auto resourcePath = OGLE::FileHandler::GetResourcePath();
	auto squarePath = OGLE::FileHandler::FindResource("square.png");
	auto vertexShaderPath = OGLE::FileHandler::FindResource("vertexShader.shader");
	auto fragmentPath = OGLE::FileHandler::FindResource("fragmentShader.shader");
	
	
	Application application("Game", 1280, 720, 4, 4);
	Camera2D cam;

	Shader shader(vertexShaderPath, fragmentPath);
	Registry::AssetRegistry<Shader>::Insert("default", &shader);

	Texture texture(squarePath);
	Registry::AssetRegistry<Texture>::Insert("default", &texture);


	Sprite sprite(
		Registry::AssetRegistry<Texture>::Get("default"),
		Registry::AssetRegistry<Shader>::Get("default"));

	PlayerObject player(&sprite);
	
	Renderer renderer(&cam);
	renderer.AddRenderTarget(&player);

	
	Input::InputManager inputManager;

	Time time;
	Cursor cursor;

	
	while (!application.WindowShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.50f, 0.5f, 0.6f, 1.0f);

		renderer.InputSetupActor(&inputManager);
		renderer.BeginActors();
		renderer.TickActors(time.deltaTime);
		
		time.UpdateTime();
		cursor.UpdateMouse(application.GetWindow());
		inputManager.PollInputEvent(application.GetWindow());

		
		
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