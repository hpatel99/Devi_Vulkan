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
	VkInstance *instance;
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

	//intialize vulkan instance
	void initVulkan()
	{
		//App info .. this one is optional but gives more info.. .we will see if it useful in future. Else will cull it
		VkApplicationInfo appInfo;
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Game";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "None???";
		appInfo.apiVersion = VK_API_VERSION_1_0;

		// Create_info this is not optional and defines validation layer app wide and not limited to device.
		// What does this mean?? i dont know will find in future

		VkInstanceCreateInfo createInfo;
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;



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