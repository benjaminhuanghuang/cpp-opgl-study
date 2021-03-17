#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 textureCoord;

out vec3 passColor;
out vec2 passTextureCoord;

//uniform mat4 transform;
//uniform mat4 view;
//uniform mat4 projection;

void main() {
	gl_Position = vec4(position, 1.0);//projection * view * transform *vec4(position, 1.0);
	passColor = color;
	passTextureCoord = textureCoord;
}