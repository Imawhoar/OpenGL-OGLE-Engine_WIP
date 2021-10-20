#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "OGLE.h"
using namespace OGLE;

void EngineStuff()
{

	auto squarePath = OGLE::FileHandler::GetResourcePath("square.png");
	auto vertexShaderPath = OGLE::FileHandler::GetResourcePath("vertexShader.shader");
	auto fragmentPath = OGLE::FileHandler::GetResourcePath("fragmentShader.shader");


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

	inputManager.CreateAction("moveRightward");
	inputManager.CreateAction("rotateBody");
	inputManager.CreateAction("moveForward");

	inputManager.CreateAction("fakeZoom");
	inputManager.GetAction("fakeZoom")->SetInputType(InputType::Mouse);
	
	inputManager.AddKey("moveRightward", KeyCode::KEY_D, 1.0f);
	inputManager.AddKey("moveRightward", KeyCode::KEY_A, -1.0f);
	
	inputManager.AddKey("rotateBody", KeyCode::KEY_E, 1.0f);
	inputManager.AddKey("rotateBody", KeyCode::KEY_Q, -1.0f);

	inputManager.AddKey("moveForward", KeyCode::KEY_W, 1.0f);
	inputManager.AddKey("moveForward", KeyCode::KEY_S, -1.0f);

	inputManager.AddKey("fakeZoom", MouseCode::MOUSE_LEFT, 1.0f);
	inputManager.AddKey("fakeZoom", MouseCode::MOUSE_RIGHT, -1.0f);




	renderer.InputSetupActor(&inputManager);
	renderer.BeginActors();

	Color backgroundColor(120.0f, 102.0f, 60.0f);
	while (!application.WindowShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(backgroundColor.R01(), backgroundColor.G01(), backgroundColor.B01(), backgroundColor.A());

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