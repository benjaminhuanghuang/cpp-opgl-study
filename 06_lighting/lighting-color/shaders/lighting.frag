// Request GLSL 3.3
#version 330

out vec4 color;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
  color = vec4(lightColor * objectColor, 1.0f); 
}
