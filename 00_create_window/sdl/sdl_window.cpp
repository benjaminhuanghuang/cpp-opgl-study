#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>

bool isRunning = true;

void processInput(){
  SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
}


int main(void)
{
  // Set OpenGL attributes
  // Use the core OpenGL profile
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  // Specify version 3.3
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  // Request a color buffer with 8-bits per RGBA channel
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  // Enable double buffering
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  // Force OpenGL to use hardware acceleration
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

  SDL_Window *mWindow = SDL_CreateWindow("OpenGL widnow using SDL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
  if (!mWindow)
  {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }

  // Create an OpenGL context
  SDL_GLContext mContext = SDL_GL_CreateContext(mWindow);

  // Initialize GLEW
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK)
  {
    SDL_Log("Failed to initialize GLEW.");
    return false;
  }

  // Initialize GLEW
  glewExperimental = true; // Needed for core profile
  if (glewInit() != GLEW_OK)
  {
    SDL_Log("Failed to initialize GLEW.");
    exit(EXIT_FAILURE);
  }

  glViewport(0, 0, 640, 480);

  while (isRunning)
  {
    processInput();

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing ...

    // Swap the buffers
	  SDL_GL_SwapWindow(mWindow);
  }
  SDL_Quit();
}