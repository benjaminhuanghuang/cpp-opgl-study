

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