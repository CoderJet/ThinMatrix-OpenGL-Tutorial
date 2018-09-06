#version 330 core

in vec2 texCoords;
in vec3 surfaceNormal;
in vec3 toLightVector;

out vec4 returnColor;

uniform sampler2D textureSampler;
uniform vec3 lightColour;

void main()
{
	vec3 unitNormal = normalize(surfaceNormal);
	vec3 unitLightVector = normalize(toLightVector);

	float nDot1 = dot(unitNormal, unitLightVector);
	float brightness = max(nDot1, 0.0);
	vec3 diffuse = brightness * lightColour;

	returnColor = vec4(diffuse, 1.0) * texture(textureSampler, texCoords);
}