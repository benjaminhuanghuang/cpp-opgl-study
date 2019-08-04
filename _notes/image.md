# Image loading library
There are some image libraries can be used to load the texture for OpenGL

## Using SOIL
```
  #include <SOIL.h>

  unsigned char* image = SOIL_load_image(fileName.c_str(), &mWidth, &mHeight, &channels, SOIL_LOAD_AUTO);
	
	if (image == nullptr)
	{
		SDL_Log("SOIL failed to load image %s: %s", fileName.c_str(), SOIL_last_result());
		return false;
	}
	
  // ... do something with the image
	
	SOIL_free_image_data(image);
```



## Using stb_image
https://github.com/nothings/stb

```
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

// ...

int width, height, channels;
stbi_set_flip_vertically_on_load(true);
unsigned char *image = stbi_load("path_to_raster_image.jpg",
                                 &width,
                                 &height,
                                 &channels,
                                 STBI_rgb);

// ... do something with the image

stbi_image_free(image);
```
这是因为OpenGL要求y轴0.0坐标是在图片的底部的，但是图片的y轴0.0坐标通常在顶部, stb_image.h能够在图像加载时帮助我们翻转y轴，只需要在加载任何图像前加入以下语句即可：
```
  stbi_set_flip_vertically_on_load(true);
```