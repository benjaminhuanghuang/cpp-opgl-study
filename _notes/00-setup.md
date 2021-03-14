
## Window management
OpenGL实际上并不是把图像直接绘制到计算机屏幕上，而是渲染到一个帧缓冲区，然后需要由这台机器来负责把帧缓冲区的内容绘制到屏幕上的一个窗口中

GLFW (Graphics Library Framework) free, Open Source, multi-platform library for OpenGL, OpenGL ES and Vulkan application development. It provides API for creating windows, contexts and surfaces, reading input, handling events, etc.

```
  brew install glfw

  /usr/local/Cellar/glfw/3.3.2
```
GLFW窗要调用glfwMakeContextCurrent() 将它与当前OpenGL上下文关联起来


## Extension

- GLEW (OpenGL Extension Wrangler Library) get all extensions avaliable, should be included before GLFW
```
  brew install grew

  /usr/local/Cellar/glew/2.1.0_1
```

- GLAD



## Math
OpenGL Mathematics，一般称作GLM。它是一个只有头文件的C++库，兼容Windows、macOS和Linux


## Texture Loader
- SOIL2