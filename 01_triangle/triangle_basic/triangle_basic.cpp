/*
  OpenGL does NOT work without shader
*/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>

float vertices[] = {
    -0.5f, -0.5f, 0.0f, // bottom left
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

const GLchar *vertexShaderSource = "#version 330 core\n"
                                   "layout (location = 0) in vec3 position;\n"
                                   "void main(){ \n"
                                   "gl_Position = vec4( position.x, position.y, position.z, 1.0);\n"
                                   "}";

const GLchar *fragmentShaderSource = "#version 330 core\n"
                                     "out vec4 color;\n"
                                     "void main(){ \n"
                                     "color = vec4(1.0f, 0.5f, 0.1f, 1.0f);\n"
                                     "}";

void processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, true);
  }
}

int main(void)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  // Initialize GLEW
  glewExperimental = true; // Needed for core profile
  if (glewInit() != GLEW_OK)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glViewport(0, 0, 640, 480);
  //**********************************************************
  // Prepare opengl drawing
  //**********************************************************
  GLuint VAO;
  glGenVertexArrays(1, &VAO); // create 1 vao
  glBindVertexArray(VAO);

  GLuint VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  // Give our vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(
      0,                 // attribute 0. No particular reason for 0, but must match the layout in the shader.
      3,                 // size
      GL_FLOAT,          // type
      GL_FALSE,          // normalized?
      3 * sizeof(float), // stride
      (void *)0          // array buffer offset
  );
  glEnableVertexAttribArray(0);
  // unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  //**********************************************************
  // Load, compile shader
  //**********************************************************
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  GLint success;
  GLchar info[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, info);
    std::cout << "ERROR: shader vertext compilation failed. " << info << std::endl;
  }

  GLuint fragementShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragementShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragementShader);
  glGetShaderiv(fragementShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragementShader, 512, NULL, info);
    std::cout << "ERROR: shader fragement compilation failed. " << info << std::endl;
  }
  // Link and use shader
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragementShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(shaderProgram, 512, NULL, info);
    std::cout << "ERROR: shader program link failed. " << info << std::endl;
  }
  // Rlease resource
  glDeleteShader(vertexShader);
  glDeleteShader(fragementShader);

  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //********************************************
    // Draw triangle
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);
    //********************************************

    //
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1,&VBO);
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}