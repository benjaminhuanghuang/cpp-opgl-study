// Request GLSL 3.3
#version 330

// color from vertex shader
in vec3 ourColor; 

// This corresponds to the output color to the color buffer
out vec4 outColor;

void main()
{
  outColor = vec4(ourColor, 1.0);
}
