#include "../common/myOpgl.h"
#include "../common/myMesh.h"
//
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//

void processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, true);
  }
}

// Create "Simple" View-Projection Matrix for 2D
glm::mat4 CreateSimpleViewProj(float width, float height)
{
  float temp[16] =
      {
          2.0f / width, 0.0f, 0.0f, 0.0f,
          0.0f, 2.0f / height, 0.0f, 0.0f,
          0.0f, 0.0f, 1.0f, 0.0f,
          0.0f, 0.0f, 1.0f, 1.0f};
  return glm::make_mat4(temp);
}

glm::mat4 CreateTransformationMatrix(const glm::vec3 &translation, float rx, float ry, float rz, float scale)
{
  glm::mat4 matrix(1.0f);
  matrix = glm::translate(matrix, translation);
  matrix = glm::rotate(matrix, rx, glm::vec3(1, 0, 0));
  matrix = glm::rotate(matrix, ry, glm::vec3(0, 1, 0));
  matrix = glm::rotate(matrix, rz, glm::vec3(0, 0, 1));
  matrix = glm::scale(matrix, glm::vec3(scale, scale, scale));

  return matrix;
}

float vertices[] = {
    -0.5f, 0.5f, 0.f, 0.f, 0.f, 0.0f, 0.f, 0.f, // top left
    0.5f, 0.5f, 0.f, 0.f, 0.f, 0.0f, 1.f, 0.f,  // top right
    0.5f, -0.5f, 0.f, 0.f, 0.f, 0.0f, 1.f, 1.f, // bottom right
    -0.5f, -0.5f, 0.f, 0.f, 0.f, 0.0f, 0.f, 1.f // bottom left
};

unsigned int indices[] = {
    0, 1, 2,
    2, 3, 0};

int main(void)
{
  int screenWidth = 1024;
  int screenHeight = 768;
  //Create the window and the OpenGL context
  GLFWwindow *window = CreateWindow(screenWidth, screenHeight, "OpenGL Cube");

  //**********************************************************
  // Load shaders
  GLuint shaderProgramID = LoadShaders("shaders/Sprite.vert", "shaders/Sprite.frag");
  glUseProgram(shaderProgramID);

  //**********************************************************
  // Load texture
  GLuint textureID = LoadTexture("images/Radar.png");
  glBindTexture(GL_TEXTURE_2D, textureID);

  //**********************************************************
  // Load vertext
  GLuint vertexArrayID = CreateVertexArray();

  GLuint vertexBufferID = CreateVertexBuffer(vertices, sizeof(vertices));

  GLuint indexBufferID = CreateIndexBuffer(indices, sizeof(indices));

  // create index buffer
  // Position attribute
  glVertexAttribPointer(
      0,                   // Attribute index
      3,                   // Number of components (x,y,z)
      GL_FLOAT,            // Component type
      GL_FALSE,            // Normolize
      8 * sizeof(GLfloat), // Stride, size of vertext
      (GLvoid *)0          // offest from start of vertext to this attribute
  );

  glEnableVertexAttribArray(0);
  // TexCoord attribute
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
  glEnableVertexAttribArray(1);
  // Use vertex array
  glBindVertexArray(vertexArrayID);

  //
  glm::mat4 viewProj = CreateSimpleViewProj(screenWidth, screenHeight);
  GLuint loc = glGetUniformLocation(shaderProgramID, "uViewProj");
  // Send the matrix data to the uniform
  glUniformMatrix4fv(loc, 1, GL_TRUE, glm::value_ptr(viewProj));

  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    // Clear the screen to dark blue background
    glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //-------------Draw 2D ---------------------------------------------
    // Scale the quad by the width/height of texture
    glm::mat4 scaleMat = glm::scale(glm::mat4(1.0f), glm::vec3(256.0f, 256.0f, 1.0f));

    glm::mat4 world = scaleMat * CreateTransformationMatrix(glm::vec3(375.0f, -275.0f, 0.0f), 0, 0, 0, 1);

    // Set world transform
    GLuint loc = glGetUniformLocation(shaderProgramID, "uWorldTransform");
    // Send the matrix data to the uniform
    glUniformMatrix4fv(loc, 1, GL_TRUE, glm::value_ptr(world));

    // Draw quad
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    //----------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  //---------------------------------------------------------------
  // Clean vertex array object
  glDeleteBuffers(1, &vertexBufferID);
  //glDeleteBuffers(1, &indexBufferID);
  glDeleteVertexArrays(1, &vertexArrayID);
  //
  glDeleteProgram(shaderProgramID);
  //
  glDeleteTextures(1, &textureID);
  // clean up window
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}