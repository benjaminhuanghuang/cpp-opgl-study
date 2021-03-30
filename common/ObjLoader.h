#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

class ObjLoader
{

public:
  static class VertexArray *LoadMesh(const std::string &fileName);

private:
  static void ProcessVertex(std::vector<std::string> const &vertexData,
                            std::vector<glm::vec3> const &positions,
                            std::vector<glm::vec2> const &texCoords,
                            std::vector<glm::vec3> const &normals,
                            std::vector<GLfloat> &vertices,
                            std::vector<GLuint> &indices);
  static std::vector<std::string> split(const std::string &s, const char &c);
};