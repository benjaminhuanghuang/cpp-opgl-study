#include "Display.h"
#include <iostream>

Display::Display(int w, int h, const std::string &title)
{
  if (!glfwInit())
    exit(EXIT_FAILURE);

  // Set all the required options for GLFW
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  // for Mac
  // https://stackoverflow.com/questions/22887922/glfw-fails-to-open-window-in-osx
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  m_window = glfwCreateWindow(w, h, title.c_str(), NULL, NULL);

  if (!m_window)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(m_window);
  // Set the required callback functions
  glfwSetKeyCallback(m_window, key_callback);

  // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
  glewExperimental = GL_TRUE;
  // Initialize GLEW to setup the OpenGL Function pointers
  if (glewInit() != GLEW_OK)
  {
    std::cout << "Failed to initialize GLEW" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Define the viewport dimensions
  int width, height;
  glfwGetFramebufferSize(m_window, &width, &height);
  glViewport(0, 0, width, height);
}

Display::~Display()
{
  glfwDestroyWindow(m_window);
  // Terminate GLFW, clearing any resources allocated by GLFW.
  glfwTerminate();
}

void Display::Update()
{
  glfwSwapBuffers(m_window);
}

void Display::Loop()
{
  while (!glfwWindowShouldClose(m_window))
  {
    // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
    glfwPollEvents();

    // Render
    // Clear the colorbuffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap the screen buffers
    glfwSwapBuffers(m_window);
  }
}

void Display::key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
  std::cout << key << std::endl;
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}