

1. 修改顶点着色器，以便将3个不同的点输出到后续的管线阶段；

2. 修改glDrawArrays()调用，指定3个顶点。

在glDrawArrays()调用中 指定了GL_TRIANGLES（而非GL_POINTS），同时也指定了管线中有3个顶点。
这样顶点着色器会在每个迭代运行3遍，内置变量gl_VertexID会自增（初始值为0）。
通过检测gl_VertexID的值，着色器设计为可以在每次运行时输出不同的点。前面说到这3个点之后会经过光栅化阶段，生成一个填充过的三角形。



## How to generate the vertices data
使用建模软件，create plane



