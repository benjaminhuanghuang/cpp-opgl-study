// Request GLSL 3.3
#version 330

in vec2 texCoord;

// This corresponds to the output color to the color buffer
out vec4 outColor;
uniform sampler2D ourTexture;

void main()
{
  outColor = texture(ourTexture, texCoord); 
}
