#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>

// openGL 绘制部分
void opengldraw()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char *argv[])
{
  // 设置 SDL 版本和信息
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window *window = SDL_CreateWindow("SDL+OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 300, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  SDL_GL_CreateContext(window);
  SDL_GL_SetSwapInterval(1);
  glewInit();

  bool quit = false;
  SDL_Event event;

  while (quit == false)
  {

    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
        quit = true;
    }
    opengldraw();
    SDL_GL_SwapWindow(window);
    SDL_Delay(1000 / 60);
  }

  SDL_DestroyWindow(window);
  return 0;
}