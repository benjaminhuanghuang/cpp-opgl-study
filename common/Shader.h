#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <GL/glew.h>
#include "GLFW/glfw3.h"

class Shader
{
public:
  Shader(const char *vertexPath, const char *fragemnetPath);
  std::string vertexString;
  std::string fragementString;
  const char* vertexSource;
  const char* fragementSource;
  // Shader program ID
  GLint ID;
  void use();
private:
  void checkCompileErrors(GLint id);
  void checkLinkErrors(GLint id);
};

#endif
