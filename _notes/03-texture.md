## Texture Mapping
Texture mapping is a technique for rendering a texture (image) on the face of a triangle. It allows you to use colors from a texture when drawing a triangle instead of using just a solid color.

To correctly apply a texture to a model, you need to know which parts of the texture should correspond to which triangles.

To support this, you need an additional vertex attribute for every vertex in the vertex buffer. Previously, the vertex attributes only stored a 3D position in each vertex. For texture mapping, each vertex also needs a **texture coordinate** that specifies the location in the texture that corresponds to that vertex.”

## U V 坐标

Texture coordinates typically are normalized coordinates. In OpenGL, the coordinates are such that the bottom-left corner of the texture is (0, 0) and the top-right corner is (1, 1),

UV coordinates is a synonym for texture coordinates.

To use texture mapping in OpenGL, there are three things you need to do:
- Load image files (textures) and create OpenGL texture objects.
- Update the vertex buffer format to include texture coordinates.
- Tell the shaders to use the textures.

## 环绕模式
GL_REPEAT	          对纹理的默认行为。重复纹理图像。
GL_MIRRORED_REPEAT	和GL_REPEAT一样，但每次重复图片是镜像放置的。
GL_CLAMP_TO_EDGE	  纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果。
GL_CLAMP_TO_BORDER	超出的坐标为用户指定的边缘颜色


##ß
```
  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
```

## Shader
```
  // This should correspond to the data stored for each vertex in the vertex buffer.
  layout (location = 0) in vec3 inPosition; 
  layout (location = 1) in vec3 inColor; 
  layout (location = 2) in vec2 inTexCoord; 

  out vec3 ourColor; // to fragment shader
  out vec2 texCoord;

  void main()
  {
    gl_Position = vec4(inPosition, 1.0);
    ourColor = inColor;
    texCoord = vec2(inTexCoord.x, 1.0 - inTexCoord.y);
  }
```

```
  out vec4 outColor;
  uniform sampler2D ourTexture1;

  void main()
  {
    outColor = texture(ourTexture1, texCoord);
  }
```