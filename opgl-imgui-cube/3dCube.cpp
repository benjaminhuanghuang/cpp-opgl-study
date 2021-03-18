#include "opgl.h"

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(void)
{
    //Create the window and the OpenGL context
    GLFWwindow *window = CreateWindow(1480, 950);

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
        glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //----------------------------------------------------------
        // Draw container
        glDrawElements(
            GL_TRIANGLES, // Type of polygon/primitive to draw
            6, // Number of indices in index buffer
            GL_UNSIGNED_INT, // Type of each index
            nullptr // Usually nullptr
        );

        //----------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //---------------------------------------------------------------
    // Clean vertex array object
    glDeleteBuffers(1, &vertexBufferID);
    glDeleteBuffers(1, &indexBufferID);
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