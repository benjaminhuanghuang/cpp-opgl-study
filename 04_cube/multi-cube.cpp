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

glm::vec3 cubePositions[] = {
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f, 3.0f, -7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f, 2.0f, -2.5f),
    glm::vec3(1.5f, 0.2f, -1.5f),
    glm::vec3(-1.3f, 1.0f, -1.5f)};

int main(void)
{
    int screenWidth = 1480;
    int screenHeight = 950;
    //Create the window and the OpenGL context
    GLFWwindow *window = CreateWindow(screenWidth, screenHeight, "OpenGL Cube");

    //**********************************************************
    // Load shaders
    GLuint shaderProgramID = LoadShaders("shaders/cube.vert", "shaders/cube.frag");
    glUseProgram(shaderProgramID);

    //**********************************************************
    // Load texture
    GLuint textureID = LoadTexture("images/wood.png");
    glBindTexture(GL_TEXTURE_2D, textureID);

    //**********************************************************
    // Load vertext
    GLuint vertexArrayID = CreateVertexArray();

    GLuint vertexBufferID = CreateVertexBuffer(cube_vertices, sizeof(cube_vertices));

    GLuint indexBufferID = CreateIndexBuffer(cube_indexes, sizeof(cube_indexes));

    // create index buffer
    // Position attribute
    glVertexAttribPointer(
        0,                   // Attribute index
        3,                   // Number of components (x,y,z)
        GL_FLOAT,            // Component type
        GL_FALSE,            // Normolize
        5 * sizeof(GLfloat), // Stride, size of vertext
        (GLvoid *)0          // offest from start of vertext to this attribute
    );
    glEnableVertexAttribArray(0);
    // TexCoord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    // Use vertex array
    glBindVertexArray(vertexArrayID);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // Clear the screen to dark blue background
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //----------------------------------------------------------
        // Draw mesh

        for (unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model;
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            ourShader.setMat4("model", model);

            glDrawElements(
                GL_TRIANGLES,         // Type of polygon/primitive to draw
                sizeof(cube_indexes), // Number of indices in index buffer
                GL_UNSIGNED_INT,      // Type of each index
                nullptr               // Usually nullptr
            );
        }

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