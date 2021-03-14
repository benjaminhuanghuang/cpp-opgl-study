## Reference
- ImGui in OpenGL
  - https://www.youtube.com/watch?v=nVaQuNXueFw&t=447s&ab_channel=TheCherno

- 现代OpenGL教程（一）：绘制三角形（imgui+OpenGL3.3）
  - https://blog.csdn.net/MASILEJFOAISEGJIAE/article/details/84840748
  

## imgui files
Copy all necessary : 
```
imgui_impl_opengl3.h,
imgui_impl_opengl3.cpp,
imgui_impl_glfw.h
mgui_impl_glfw.cpp
imgui.cpp
imgui_demo.cpp
imgui_draw.cpp
```
Include all header files 
```
imgui.h
imgui_impl_opengl3.h
imgui_impl_glfw.h
```
## Full ImGui code for reference:
```
//Setup IMGUI
IMGUI_CHECKVERSION();
ImGui::CreateContext();
ImGuiIO& io = ImGui::GetIO(); (void)io;
ImGui::StyleColorsDark();
ImGui_ImplGlfw_InitForOpenGL(window, true);
ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));

//New Frame
ImGui_ImplOpenGL3_NewFrame();
ImGui_ImplGlfw_NewFrame();
ImGui::NewFrame();

//Render
ImGui::Render();
ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

//Shutdown
ImGui_ImplOpenGL3_Shutdown();
ImGui_ImplGlfw_Shutdown();
ImGui::DestroyContext();
```