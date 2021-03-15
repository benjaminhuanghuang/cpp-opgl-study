
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
