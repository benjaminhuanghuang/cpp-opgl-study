#include "opgl.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

const char *glsl_version = "#version 150";

float rotate_x = 0;
float rotate_y = 0;
float rotate_z = 0;

float x = 0;
float y = 0;
float z = -3.0;

float rotate_speed = 50;

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(void)
{
    int screenWidth = 1480;
    int screenHeight = 950;
    //Create the window and the OpenGL context
    GLFWwindow *window = CreateWindow(screenWidth, screenHeight);

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

    //创建并绑定ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // Clear the screen to dark blue background
        glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Create transformations
        glm::mat4 trasform(1.0f);
        glm::mat4 view(1.0f);
        glm::mat4 projection;
        projection = glm::perspective(45.0f, (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);
        //trasform = glm::rotate(trasform, (GLfloat)glfwGetTime() * 1.0f, glm::vec3(glm::vec3(rotate_x, rotate_y, rotate_z))); // use with perspective projection
        trasform = glm::rotate(trasform, 1.0f, glm::vec3(glm::vec3(rotate_x, rotate_y, rotate_z))); // use with perspective projection
        //trasform = glm::rotate(trasform, 1.0f, glm::vec3(0.5f, 1.0f, 0.0f)); // use with perspective projection
        view = glm::translate(view, glm::vec3(x, y, z)); // use with perspective projection

        // Get their uniform location
        GLint transformLoc = glGetUniformLocation(shaderProgramID, "transform");
        GLint viewLoc = glGetUniformLocation(shaderProgramID, "view");
        GLint projLoc = glGetUniformLocation(shaderProgramID, "projection");
        // Pass them to the shaders
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trasform));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        //----------------------------------------------------------
        // Draw mesh
        glDrawElements(
            GL_TRIANGLES,         // Type of polygon/primitive to draw
            sizeof(cube_indexes), // Number of indices in index buffer
            GL_UNSIGNED_INT,      // Type of each index
            nullptr               // Usually nullptr
        );

        //----------------------------------------------------------
        // ImGui
        {
            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::Begin("Control Panel"); // Create a ImGui window called "Control Panel"

            ImGui::SliderFloat("x", &x, -100, 100);
            ImGui::SliderFloat("y", &y, -100, 100);
            ImGui::SliderFloat("z", &z, 0, -100);

            ImGui::SliderFloat("rotate x", &rotate_x, -3.14f, 3.14f);
            ImGui::SliderFloat("rotate y", &rotate_y, -3.14f, 3.14f);
            ImGui::SliderFloat("rotate z", &rotate_z, -3.14f, 3.14f);
            if (ImGui::Button("Reset")) // Buttons return true when clicked
            {
                rotate_x = 0;
                rotate_y = 0;
                rotate_z = 0;

                x = 0;
                y = 0;
                z = -3.0;
            }

            ImGui::End();

            // Rendering
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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