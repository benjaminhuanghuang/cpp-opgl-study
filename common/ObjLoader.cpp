#include "ObjLoader.h"
#include "VertexArray.h"

VertexArray *ObjLoader::LoadMesh(std::string const &filename)
{
  std::ifstream fin(filename.c_str());

  if (!fin.is_open())
  {
    std::cerr << "[ERROR]: Failed to open file: " << filename << std::endl;
    exit(EXIT_FAILURE);
  }

  // read file to
  std::vector<glm::vec3> temp_vertices;
  std::vector<glm::vec2> temp_uvs;
  std::vector<glm::vec3> temp_normals;

  // put verext data to
  std::vector<GLfloat> vertices;
  std::vector<GLuint> indices;

  std::string line;
  bool processFace = false;
  while (std::getline(fin, line))
  {
    std::vector<std::string> tokens = split(line, ' ');
    if (tokens.empty())
    {
      continue;
    }
    if (tokens[0] == "v")
    {
      temp_vertices.push_back(glm::vec3(stof(tokens[1]), stof(tokens[2]), stof(tokens[3])));
    }
    else if (tokens[0] == "vt")
    {
      //  Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
      temp_uvs.push_back(glm::vec2(stof(tokens[1]), stof(tokens[2])));
    }
    else if (tokens[0] == "vn")
    {
      temp_normals.push_back(glm::vec3(stof(tokens[1]), stof(tokens[2]), stof(tokens[3])));
    }
    else if (tokens[0] == "f")
    {
      if (!processFace)
      {
        vertices = std::vector<GLfloat>(8 * temp_vertices.size());
        processFace = true;
      }
      std::vector<std::string> vertex1 = split(tokens[1], '/');
      std::vector<std::string> vertex2 = split(tokens[2], '/');
      std::vector<std::string> vertex3 = split(tokens[3], '/');

      ProcessVertex(vertex1, temp_vertices, temp_uvs, temp_normals, vertices, indices);
      ProcessVertex(vertex2, temp_vertices, temp_uvs, temp_normals, vertices, indices);
      ProcessVertex(vertex3, temp_vertices, temp_uvs, temp_normals, vertices, indices);
    }
  }

  return new VertexArray(vertices.data(), vertices.size() / 8, indices.data(), indices.size());
}

std::vector<std::string> ObjLoader::split(const std::string &s, const char &c)
{
  std::string buff{""};
  std::vector<std::string> v;

  for (auto n : s)
  {
    if (n != c)
      buff += n;
    else if (n == c && buff != "")
    {
      v.push_back(buff);
      buff = "";
    }
  }
  if (buff != "")
    v.push_back(buff);

  return v;
}
void ObjLoader::ProcessVertex(std::vector<std::string> const &vertexIndex,
                              std::vector<glm::vec3> const &temp_vertices,
                              std::vector<glm::vec2> const &temp_uvs,
                              std::vector<glm::vec3> const &temp_normals,
                              std::vector<GLfloat> &vertices,
                              std::vector<GLuint> &indices)
{
  GLuint idx = stoi(vertexIndex[0]) - 1;
  indices.push_back(idx);

  glm::vec3 position = temp_vertices[idx];
  vertices[idx * 8] = position.x;
  vertices[idx * 8 + 1] = position.y;
  vertices[idx * 8 + 2] = position.z;

  glm::vec3 normal = temp_normals[stoi(vertexIndex[2]) - 1];
  vertices[idx * 8 + 3] = normal.x;
  vertices[idx * 8 + 3 + 1] = normal.y;
  vertices[idx * 8 + 3 + 2] = normal.z;

  glm::vec2 texCoord = temp_uvs[stoi(vertexIndex[1]) - 1];
  vertices[idx * 8 + 6] = texCoord.x;
  vertices[idx * 8 + 6 + 1] = texCoord.y;
}