
# SOIL
Although you can use the SDL Image library to load images for OpenGL, the Simple OpenGL Image Library (SOIL) is a little easier to use. 

SOIL can read in several file formats, including PNG, BMP, JPG, TGA, and DDS. As it’s designed to work with OpenGL, it slots in easily with the other OpenGL code needed for creating a texture object.

It is based on stb_image version 1.16

https://github.com/kbranigan/Simple-OpenGL-Image-Library

```
  https://github.com/kbranigan/Simple-OpenGL-Image-Library

  make install
  cp lib/libSOIL.a /usr/local/lib/
  cp src/SOIL.h /usr/local/include/
```