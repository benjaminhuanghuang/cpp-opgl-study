// Request GLSL 3.3
#version 330

// This corresponds to the output color to the color buffer
out vec4 outColor;

void main()
{
	// RGBA of 100% red, 50% opaque
  outColor = vec4(1.0, 0.0, 0.0, 0.0);
}
