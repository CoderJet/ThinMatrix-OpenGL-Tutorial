#version 330 core

in vec3 color;

out vec4 returnColor;

void main()
{
	returnColor = vec4(color, 1.0);
}