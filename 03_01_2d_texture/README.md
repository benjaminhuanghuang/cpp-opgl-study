## Texture Mapping
Texture mapping is a technique for rendering a texture (image) on the face of a triangle. It allows you to use colors from a texture when drawing a triangle instead of using just a solid color.

To correctly apply a texture to a model, you need to know which parts of the texture should correspond to which triangles.

To support this, you need an additional vertex attribute for every vertex in the vertex buffer. Previously, the vertex attributes only stored a 3D position in each vertex. For texture mapping, each vertex also needs a **texture coordinate** that specifies the location in the texture that corresponds to that vertex.”

Texture coordinates typically are normalized coordinates. In OpenGL, the coordinates are such that the bottom-left corner of the texture is (0, 0) and the top-right corner is (1, 1),

UV coordinates is a synonym for texture coordinates.


To use texture mapping in OpenGL, there are three things you need to do:
- Load image files (textures) and create OpenGL texture objects.
- Update the vertex buffer format to include texture coordinates.
- Tell the shaders to use the textures.”
