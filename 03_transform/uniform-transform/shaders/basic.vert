#version 330

// This should correspond to the data stored for each vertex in the vertex buffer.
layout (location = 0) in vec3 inPosition; 
layout (location = 1) in vec3 inColor; 
layout (location = 2) in vec2 inTexCoord; 

out vec3 ourColor; // to fragment shader
out vec2 texCoord;
uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(inPosition, 1.0);
	ourColor = inColor;
	texCoord = vec2(inTexCoord.x, 1.0 - inTexCoord.y);
}
