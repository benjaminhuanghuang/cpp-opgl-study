// Request GLSL 3.3
#version 330

// Attribute 0 is position, 1 is normal, 2 is tex coords.
in vec3 inPosition;

void main()
{
	// Convert position to homogeneous coordinates
	gl_Position = vec4(inPosition, 1.0);
}