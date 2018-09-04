#version 330 core

in vec3 position;
in vec2 textureCoords;

out vec2 texCoords;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main()
{
	gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4(position, 1.0);
	texCoords = textureCoords;
}