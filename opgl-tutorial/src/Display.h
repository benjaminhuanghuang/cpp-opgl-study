#pragma once
#include <string>
#include <GL/glew.h>
#include "GLFW/glfw3.h"

class Display
{
public:
  Display(int w, int h, const std::string &title);

  void Update();

  void Loop();

  ~Display();

private:
  GLFWwindow *m_window;
  static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
};