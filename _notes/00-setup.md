
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
GLAD是一个开源的库，功能跟 GLEW 类似。GLAD 使用了一个在线服务（能够告诉 GLAD 需要定义的 OpenGL 版本，并且根据这个版本加载所有相关的 OpenGL 函数）
glad会提供一个zip压缩文件，包含两个头文件目录，和一个glad.c文件，如下

```
/Users/Desktop/glad
├── include
│   ├── KHR
│   │   └── khrplatform.h
│   └── glad
│       └── glad.h
└── src
    └── glad.c
```
将两个头文件目录（glad和KHR）复制到/usr/local/include，并添加glad.c到工程中


## Math
OpenGL Mathematics，一般称作GLM。它是一个只有头文件的C++库，兼容Windows、macOS和Linux
```
  brew install glm
```

## Texture Loader
- SOIL2
```
  brew install glm
```
