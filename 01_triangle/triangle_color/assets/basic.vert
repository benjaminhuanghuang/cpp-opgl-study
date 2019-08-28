// Request GLSL 3.3
#version 330

// This should correspond to the data stored
// for each vertex in the vertex buffer.
layout (location = 0) in vec3 inPosition; 
layout (location = 1) in vec3 inColor; 

out vec3 ourColor; // to fragment shader

void main()
{
	// The vertex shader needs to output a 4D coordinate.
	// For now set the 4th coordinate to 1.0
	gl_Position = vec4(inPosition, 1.0);
	ourColor = inColor;
}
