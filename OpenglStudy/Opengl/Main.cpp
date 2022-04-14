#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";


int main() {
	//std::cout << "WebGL :)" << std::endl;

	// initialize glfw
	glfwInit();

	// if glfw version is 4.3 then major = 4 and minor = 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // we are using glfw-3.3.7
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// specify core profile for modern functions
	GLFWwindow* window = glfwCreateWindow(700, 700, "OpenglTesting", NULL, NULL);
	
	// cordinates should bitween -1 to 1
	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};

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


	//
	// Creating shaders
	//


	// open gl version of unsinged interger
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	// shaders are already in the program, so delete it to release mamory
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);



	// create Vertix Array, Vertex and Fragment Buffer On=bject
	GLuint VAO, VBO, FBO;
	glGenVertexArrays(1, &VAO); // generate vao before vbo
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// configuire VAO let opengl know how to work with our VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//optional
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);



	// setting color
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// execute the buffer color
	glClear(GL_COLOR_BUFFER_BIT);
	// swap the front buffer to back buffer. As the current/front buffer is on default color and we just create the back buffer with custom background color
	glfwSwapBuffers(window);


	// while loop will stop the window from being closed automatically by calling !glfwWindowShouldClose(window) event and 
	while (!glfwWindowShouldClose(window)) {

		// setting color
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);


		// make window responsive like closeable, resizeable, dragable ect.
		glfwPollEvents();
	}

	// clean VAO VBO
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}