#version 330

// This should correspond to the data stored for each vertex in the vertex buffer.
layout (location = 0) in vec3 inPosition; 
layout (location = 1) in vec2 inTexCoord; 

out vec2 passTextureCoord;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * transform * vec4(inPosition, 1.0);
	passTextureCoord = inTexCoord;
}
