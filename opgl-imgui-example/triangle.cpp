#include <iostream>
#include <stdio.h>
//
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GL/glew.h> // Initialize with glewInit()

// Include glfw3.h after our OpenGL definitions
#include <GLFW/glfw3.h>
//
#include "shader.h"

static void glfw_error_callback(int error, const char *description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char **)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    const char *glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // for Mac

    GLFWwindow *window = glfwCreateWindow(1600, 1200, "ImGui Triangle", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    bool err = glewInit() != GLEW_OK;
    if (err)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }

    //创建并绑定ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    //ImFont* font = io.Fonts->AddFontFromFileTTF("ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    //初始化各种数据
    GLuint VBO, VAO, EBO;
    //创建一个VAO，并将它设为当前对象
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    //绑定顶点数组对象
    glBindVertexArray(VertexArrayID);

    // 加载shader文件，创建并编译GLSL程序
    GLuint programID = LoadShaders("shaders/triangle.vert", "shaders/triangle.frag");
    ImVec4 v1 = ImVec4(-0.25f, -0.25f, 0.0f, 1.00f);
    ImVec4 v2 = ImVec4(0.25f, -0.25f, 0.0f, 1.00f);
    ImVec4 v3 = ImVec4(0.0f, 0.25f, 0.0f, 1.00f);

    //定义顶点缓冲，并将顶点缓冲传给OpenGL
    GLuint vertexbuffer;

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        GLfloat g_vertex_buffer_data[] = {
            v1.x,
            v1.y,
            v1.z,
            v2.x,
            v2.y,
            v2.z,
            v3.x,
            v3.y,
            v3.z,
        };
        glGenBuffers(1, &vertexbuffer);
        // 把我们的顶点数组复制到一个顶点缓冲中，供OpenGL使用
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

        // imgui
        {
            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::Begin("imgui"); // Create a window called "imgui" and append into it.

            ImGui::Text("This is a 3D triangle."); // Display some text (you can use a format strings too)

            ImGui::End();
            // Rendering
            ImGui::Render();
        }

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        //
        // Draw Triangle

        glUseProgram(programID);

        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        //设定顶点属性指针
        glVertexAttribPointer(
            0,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,        // size
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0,        // stride
            (void *)0 // array buffer offset
        );

        // 画三角形
        // glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

        // glDisableVertexAttribArray(0);

        //
        glfwSwapBuffers(window);
    }

    // 释放VAO、VBO、EBO资源
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    /*
     OpenGL Cleanup
        release ImGui resource
        glfw release
    */

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
