

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include "../common/VertexArray.h"
#include "../common/Shader.h"
#include "../common/Texture.h"

// float vertices[] = {
//     // Position, Normal, Texture coordinates
//     -0.5f, 0.5f, 0.0f, 0, 0, 0, 0.0f, 0.0f, // top left
//     0.5f, 0.5f, 0.0f, 0, 0, 0, 1.0f, 0.0f,  // top right
//     0.5f, -0.5f, 0.0f, 0, 0, 0, 0.1f, 1.0f, // bottom right
//     -0.5f, -0.5f, 0.0f, 0, 0, 0, 0.0f, 1.0f // bottom left
// };

// unsigned int indices[] = {
//     // the index starts from 0!
//     0, 1, 2, // 第一个三角形
//     2, 3, 0  // 第二个三角形
// };
// Rectangle vertices
float vertices[] = {
    // Positions          // Colors           // Texture Coords
    0.5f, 0.5f, 0.0f,     1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Top Right
    0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,  // Bottom Right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
    -0.5f, 0.5f, 0.0f,    1.0f, 1.0f, 0.0f,   0.0f, 1.0f   // Top Left
};

GLuint indices[] =
{  // Note that we start from 0!
    0, 1, 3, // First Triangle
    1, 2, 3  // Second Triangle
};

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
    Shader shader;
    shader.Load("shaders/wall.vert", "shaders/wall.frag");

    VertexArray vao(vertices, 4, indices, 6);

    Texture texture;
    texture.Load("images/wall.png");

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // Dark blue background
        glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw
        shader.SetActive();
        vao.SetActive();
        texture.SetActive();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}