#include <iostream>
#include <GL/glew.h>
#include <SFML/window.hpp>

const GLint WIDTH = 800, HEIGHT = 600;
int main(void)
{

    sf::ContextSettings settings;

    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings ::Core;

    sf::Window window(sf::VideoMode(WIDTH, HEIGHT, 32),
                      "OpenGL SFML",
                      sf::Style::Titlebar | sf::Style::Close,
                      settings);

    // Initialize GLEW
    glewExperimental = GL_TRUE; // Needed for core profile
    if (glewInit() != GLEW_OK)
    {
        exit(EXIT_FAILURE);
    }

    bool running = true;
    while (running)
    {
        sf::Event windowEvent;

        while (window.pollEvent(windowEvent))
        {
            switch (windowEvent.type)
            {
            case sf::Event::Closed:
            {
                running = false;
                break;
            }
            }
        }

        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw OpenGL

        window.display();
    }
    window.close();
    return EXIT_SUCCESS;
}