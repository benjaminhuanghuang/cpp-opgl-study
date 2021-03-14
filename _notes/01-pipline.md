  
  ```
  glDrawArrays(GLenum mode, Glint first, Glsize count);
  ```
  mode: GL_TRIANGLE

  first : fist 定点

  count


  glCreateProgram()创建程序对象，OpenGL 程序对象包含一系列编译过的着色
  
  使用glAttachShader()将着色器加入程序对象，
  
  glLinkProgram()来请求GLSL编译器确保它们的兼容性

  glUseProgram()，它将含有两个已编译着色器的程序载入OpenGL管线阶段（在GPU上！）。注意
  glUseProgram()并没有运行着色器，它只是将着色器加载进硬件。


当准备将数据集发送给管线时是以缓冲区形式发送的。这些缓冲区最后都会被存入顶点数组对象（Vertex Array Object，VAO）中。这两行用来创建OpenGL要求的VAO。
```
  glGenVertexArrays(numVAOs, vao);
  glBindVertexArray(vao[0]);
```