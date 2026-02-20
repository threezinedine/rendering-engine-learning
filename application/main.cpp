#include "core.h"
#include <GLFW/glfw3.h>
#include <cstdio>

int main(void)
{
	NTT_LOG_SETUP();
	NTT_ASSERT(glfwInit());

	NTT_LOG_DEBUG("GLFW initialized successfully");

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
	NTT_ASSERT(window);

	NTT_LOG_DEBUG("GLFW window created successfully");

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		// glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}