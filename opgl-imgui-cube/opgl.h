#ifndef OPGL_HPP
#define OPGL_HPP
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../common/shader-c.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../common/stb_image.h"

GLFWwindow *CreateWindow(int width, int heigh)
{
	if (!glfwInit())
	{
		std::cout << "glfwInit failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	//Settings for window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// NO resize
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//Create window
	GLFWwindow *window = glfwCreateWindow(width, heigh, "CUBE", nullptr, nullptr); // Windowed
	if (!window)
	{
		std::cout << "Can not create window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Tell glfw to use the window
	glfwMakeContextCurrent(window);

	//Init GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	glViewport(0, 0, screenWidth, screenHeight);
	// Blend
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//
	glEnable(GL_DEPTH_TEST);

	return window;
}

GLuint CreateIndexBuffer(GLuint elements[], size_t size)
{
	GLuint bufferID;
	glGenBuffers(1, &bufferID);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, elements, GL_STATIC_DRAW);

	return bufferID;
}

GLuint CreateVertexBuffer(GLfloat vertices[], size_t size)
{
	GLuint bufferID;
	glGenBuffers(1, &bufferID);

	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);

	return bufferID;
}

GLuint CreateVertexArray()
{
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	return vao;
}

GLuint LoadTexture(const std::string &fileName)
{
	int width, height;
	int channels = 0;
	//
	stbi_set_flip_vertically_on_load(true);

	unsigned char *image = stbi_load(fileName.c_str(), &width, &height, &channels, 0);

	if (image == nullptr)
	{
		std::cout << "Failed to load image " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	int format = GL_RGB;
	if (channels == 4)
	{
		format = GL_RGBA;
	}
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, image);

	stbi_image_free(image);

	// Enable linear filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return textureID;
}

GLfloat cube_vertices[] = {
		-0.5, 0.5, 0.5, 1.0, 0.0, 0.0,	 // Front Top Left		- Red	- 0
		0.5, 0.5, 0.5, 0.0, 1.0, 0.0,		 // Front Top Right		- Green	- 1
		0.5, -0.5, 0.5, 0.0, 0.0, 1.0,	 // Front Bottom Right		- Blue	- 2
		-0.5, -0.5, 0.5, 0.0, 1.0, 1.0,	 // Front Bottom Left		- Cyan	- 3
		-0.5, 0.5, -0.5, 1.0, 0.0, 1.0,	 // Back Top Left		- Pink	- 4
		0.5, 0.5, -0.5, 1.0, 1.0, 0.0,	 // Back Top Right		- Yellow- 5
		0.5, -0.5, -0.5, 0.1, 0.1, 0.1,	 // Back Bottom Right		- White - 6
		-0.5, -0.5, -0.5, 1.0, 1.0, 1.0, // Back Bottom Left		- Gray  - 7
};

// prettier-ignore
GLuint cube_indexes[] = {
		0,
		3,
		2, // Front
		2,
		1,
		0,
		1,
		5,
		6, //Right
		6,
		2,
		1,
		5,
		4,
		7, //Left
		7,
		6,
		5,
		4,
		7,
		3, //Back
		3,
		0,
		4,
		4,
		5,
		1, //Top
		1,
		0,
		4,
		3,
		2,
		6, //Bottom
		6,
		7,
		3,
};

#endif