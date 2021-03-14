#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  if (!glfwInit())
    exit(EXIT_FAILURE);

  GLFWwindow *window = glfwCreateWindow(1024, 768, "glfw", NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  
  glfwMakeContextCurrent(window);

  //Get Version String
  const GLubyte *p = glGetString(GL_VERSION);
  cout << "OpenGL Version: " << p << endl;

  GLenum status = glewInit();
  if (status != GLEW_OK)
  {
    std::cerr << "glew init error " << glewGetErrorString(status) << std::endl;
  }
  return 0;
}
