# stb.image.h
image loader for texture

https://github.com/nothings/stb

只能在一个文件中加入
```
  #define STB_IMAGE_IMPLEMENTATION
```
在Y轴反转
```
  stbi_set_flip_vertically_on_load(true);
```