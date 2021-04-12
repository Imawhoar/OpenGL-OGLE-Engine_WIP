#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "OGLE.h"
using namespace OGLE;


struct TestStruct
{
	int x = 1;
	void DoSomtin()
	{
		std::cout << x << std::endl;
	}
};
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

		time.UpdateTime();
		cursor.UpdateMouse(application.GetWindow());
		inputManager.PollInput(application.GetWindow());

		renderer.BeginActors();
		renderer.TickActors(time.deltaTime);
		renderer.Render();

		glfwSwapBuffers(application.GetWindow());
		glfwPollEvents();
	}

	glfwTerminate();

}
int main() {
	//EngineStuff();


	OGLE::Template::TCallback<> test;
	TestStruct testStruct;
	testStruct.x = 333;
	TestStruct testStruct1;
	testStruct1.x = 21;
	TestStruct testStruct2;
	testStruct2.x = 55;

	test.Bind(testStruct, &TestStruct::DoSomtin);
	test.Bind(testStruct1, &TestStruct::DoSomtin);
	test.Bind(testStruct2, &TestStruct::DoSomtin);
	

	test.Invoke();
	return 0;
}