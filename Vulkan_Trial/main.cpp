#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <gl/GL.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
using namespace std;

class Game
{
public:
	void run()
	{
		initWindow();
		initVulkan();
		MainLoop();
		cleanup();

	}
private:

	// Private varaible for this class
	GLFWwindow *window;
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 600;

	//This method intialize all glfw window stuff. 
	void initWindow()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // make window not resizeable

		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan window", nullptr, nullptr);



	}

	void initVulkan()
	{

	}

	void MainLoop()
	{
		while (!glfwWindowShouldClose(window)) 
		{
			glfwPollEvents();
		}
	}

	//Remove window and memory Cleanup
	void cleanup()
	{
		glfwDestroyWindow(window);

		glfwTerminate();
	}

};



int main() {

	Game *g = new Game();

	try 
	{
		g->run();
	}
	catch (const exception e)
	{
		cerr << e.what() << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
	

	//uint32_t extensionCount = 0;
	//vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	//std::cout << extensionCount << " extensions supported\n";

	//glm::mat4 matrix;
	//glm::vec4 vec;
	//auto test = matrix * vec;

	

	

}