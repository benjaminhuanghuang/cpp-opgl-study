#version 330

// This should correspond to the data stored for each vertex in the vertex buffer.
layout (location = 0) in vec3 inPosition; 
layout (location = 1) in vec2 inTexCoord; 

out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(inPosition, 1.0);
	texCoord = inTexCoord;
}
