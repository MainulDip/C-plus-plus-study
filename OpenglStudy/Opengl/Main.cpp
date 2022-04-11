#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	//std::cout << "WebGL :)" << std::endl;

	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(700, 700, "OpenglTesting", NULL, NULL);

	if (window == NULL) {
		std::cout << "Fails to create GLFW window" << std::endl;
		std::cout << window << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);


	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}