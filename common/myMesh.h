#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
GLfloat plane_vertices[] = {
    -0.5, 0.5, 0, 0.0, 1.0,  // Top Left
    0.5, 0.5, 0, 1.0, 1.0,   // Top Right
    0.5, -0.5, 0, 1.0, 0.0,  // Bottom Right
    -0.5, -0.5, 0, 0.0, 0.0, // Bottom Left

};

// prettier-ignore
GLuint plane_indexes[] = {
    //Back face
    0, 1, 2, // first triangle
    2, 3, 0, //
};

// use with Perspective Projection
GLfloat cub_all_vertices[] = {
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
    0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
    -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
    -0.5f, 0.5f, -0.5f, 0.0f, 1.0f};

GLfloat cube_vertices[] = {
    // Back
    -0.5, 0.5, -0.5, 0.0, 1.0,  // Back Top Left
    -0.5, -0.5, -0.5, 0.0, 0.0, // Back Bottom Left
    0.5, -0.5, -0.5, 1.0, 0.0,  // Back Bottom Right
    0.5, 0.5, -0.5, 1.0, 1.0,   // Back Top Right
    // Front
    -0.5, 0.5, 0.5, 0.0, 1.0,  // Front Top Left
    -0.5, -0.5, 0.5, 0.0, 0.0, // Front Bottom Left
    0.5, -0.5, 0.5, 1.0, 0.0,  // Front Bottom Right
    0.5, 0.5, 0.5, 1.0, 1.0,   // Front Top Right
    // Right
    0.5, 0.5, -0.5, 0.0, 1.0,  // Right Top Left
    0.5, -0.5, -0.5, 0.0, 0.0, // Right Bottom Left
    0.5, -0.5, 0.5, 1.0, 0.0,  // Right Bottom Right
    0.5, 0.5, 0.5, 1.0, 1.0,   // Right Top Right

    // Left
    -0.5, 0.5, -0.5, 0.0, 1.0,  // Left Top Left
    -0.5, -0.5, -0.5, 0.0, 0.0, // Left Bottom Left
    -0.5, -0.5, 0.5, 1.0, 0.0,  // Left Bottom Right
    -0.5, 0.5, 0.5, 1.0, 1.0,   // Left Top Right

    // Top
    -0.5, 0.5, 0.5, 0.0, 1.0,  // Top Top Left
    -0.5, 0.5, -0.5, 0.0, 0.0, // Top Bottom Left
    0.5, 0.5, -0.5, 1.0, 0.0,  // Top Bottom Right
    0.5, 0.5, 0.5, 1.0, 1.0,   // Top Top Right
    // Bottom
    -0.5, -0.5, 0.5, 0.0, 1.0,  // Bottom Top Lefts
    -0.5, -0.5, -0.5, 0.0, 0.0, // Bottom Bottom Lefts
    0.5, -0.5, -0.5, 1.0, 0.0,  // Bottom Bottom Rights
    0.5, -0.5, 0.5, 1.0, 1.0,   // Bottom Top Rights
};
GLfloat cube_vertices8[] = {
    // Back
    -0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Back Top Left
    -0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Back Bottom Left
    0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Back Bottom Right
    0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Back Top Right
    // Front
    -0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Front Top Left
    -0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Front Bottom Left
    0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Front Bottom Right
    0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Front Top Right
    // Right
    0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Right Top Left
    0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Right Bottom Left
    0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Right Bottom Right
    0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Right Top Right

    // Left
    -0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Left Top Left
    -0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Left Bottom Left
    -0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Left Bottom Right
    -0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Left Top Right

    // Top
    -0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Top Top Left
    -0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Top Bottom Left
    0.5, 0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Top Bottom Right
    0.5, 0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Top Top Right
    // Bottom
    -0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0,  // Bottom Top Lefts
    -0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 0.0, 0.0, // Bottom Bottom Lefts
    0.5, -0.5, -0.5, 0.0, 0.0, 0.0, 1.0, 0.0,  // Bottom Bottom Rights
    0.5, -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0,   // Bottom Top Rights
};

//  VertexArray *va = new VertexArray(cube_vertices, sizeof(cube_vertices) / 8, cube_indexes, sizeof(cube_indexes));
GLuint cube_indexes[] = {
    //Back face
    0, 1, 3,
    3, 1, 2,

    //Front face
    4, 5, 7,
    7, 5, 6,

    //Right face
    8, 9, 11,
    11, 9, 10,

    //Left face
    12, 13, 15,
    15, 13, 14,

    //Top face
    16, 17, 19,
    19, 17, 18,

    //Bottom face
    20, 21, 23,
    23, 21, 22};
#endif