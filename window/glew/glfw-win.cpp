#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include <iostream>

int main()
{
  // Init GLFW
  if (!glfwInit())
    exit(EXIT_FAILURE);

  // Setup GLFW window propertiess
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // Core profile = No backwords compatibility
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // Alow forward compatibility
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  int w = 1024;
  int h = 768;
  //Create Window (use glfwGetPrimaryMonitor() for fullscreen)
  GLFWwindow *mainWindow = glfwCreateWindow(w, h, "OPENGL window", NULL, NULL);

  if (!mainWindow)
  { //Check Validity
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Get buffer size information
  int bufferWidth, bufferHeight;
  glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

  // Set context for GLEW to user
  glfwMakeContextCurrent(mainWindow); //Make Window Current Context

  // Allow modern extension features
  glewExperimental = GL_TRUE;

  if (glewInit() != GLEW_OK)
  {
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Setup viewport
  glViewport(0,0, bufferWidth, bufferHeight);

  while(!glfwWindowShouldClose(mainWindow)){
    // get and handle user input 
    glfwPollEvents();

    // Clear window
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(mainWindow);
  }
  return 0;
}
