
## Reference
- https://www.udemy.com/graphics-with-modern-opengl/?ranMID=39197&ranEAID=FAszdIPKpCc&ranSiteID=FAszdIPKpCc-CwbEv32EcyffesV4fP4BsQ&LSNPUBID=FAszdIPKpCc


## Vertex Specification

- VAO(Vertext Array Object): Define what data a vertext has(position, color, texture, etc)

- VBO(Vertext Buffer Objects): Defines the data.

- Attribute Pointers define where and how shaders can access vertext data

## VAO vs Shader
VAO
```
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);


  glVertexAttribPointer(N, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
  glEnableVertexAttribArray(N);

```
shader

```
  // This should correspond to the data stored for each vertex in the vertex buffer.
  layout (location = 0) in vec3 inPosition; 
  layout (location = N) in vec3 inColor; 
```

## Data type

int、float、double、uint和bool


vecn	包含n个float分量的默认向量
bvecn	包含n个bool分量的向量
ivecn	包含n个int分量的向量
uvecn	包含n个unsigned int分量的向量
dvecn	包含n个double分量的向量


## unifrom
