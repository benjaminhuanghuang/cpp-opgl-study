// Request GLSL 3.3
#version 330

// color from vertex shader
uniform vec4 theColor; 

// This corresponds to the output color to the color buffer
out vec4 outColor;

void main()
{
  outColor = theColor;
}
