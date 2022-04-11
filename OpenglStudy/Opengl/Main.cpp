#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	//std::cout << "WebGL :)" << std::endl;

	// initialize glfw
	glfwInit();

	// if glfw version is 4.3 then major = 4 and minor = 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // we are using glfw-3.3.7
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(700, 700, "OpenglTesting", NULL, NULL);
	

	if (window == NULL) {
		std::cout << "Fails to create GLFW window" << std::endl;
		std::cout << window << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// initialize/load glad
	gladLoadGL();
	// specify the viewport of the opengl in the window
	// in our case, the viewport goes from x=0, y=0, to x=700, y=700
	glViewport(0,0,700,700); // maybe optional, as its working without this line

	// setting color
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// execute the buffer color
	glClear(GL_COLOR_BUFFER_BIT);
	// swap the front buffer to back buffer. As the current/front buffer is on default color and we just create the back buffer with custom background color
	glfwSwapBuffers(window);


	// while loop will stop the window from being closed automatically by calling !glfwWindowShouldClose(window) event and 
	while (!glfwWindowShouldClose(window)) {
		// make window responsive like closeable, resizeable, dragable ect.
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}