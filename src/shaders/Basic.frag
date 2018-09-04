#version 330 core

in vec2 texCoords;

out vec4 returnColor;

uniform sampler2D textureSampler;

void main()
{
	returnColor = texture(textureSampler, texCoords);
}