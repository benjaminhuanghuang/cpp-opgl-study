#version 330

// This should correspond to the data stored for each vertex in the vertex buffer.
layout (location = 0) in vec3 inPosition; 
layout (location = 1) in vec2 inTexCoord; 

out vec2 passTextureCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = vec4(inPosition, 1.0);//projection * view * model * vec4(inPosition, 1.0);
	passTextureCoord = vec2(inTexCoord.x, 1.0 - inTexCoord.y);
}
