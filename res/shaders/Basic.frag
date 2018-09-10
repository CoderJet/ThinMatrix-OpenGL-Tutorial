#version 330 core

in vec2 texCoords;
in vec3 surfaceNormal;
in vec3 toLightVector;
in vec3 toCameraVector;
in float visibility;

out vec4 returnColor;

uniform sampler2D textureSampler;
uniform vec3 lightColour;
uniform float shineDamper;
uniform float reflectivity;
uniform vec3 skyColour;

void main()
{
	vec3 unitNormal = normalize(surfaceNormal);
	vec3 unitLightVector = normalize(toLightVector);

	float nDot1 = dot(unitNormal, unitLightVector);
	float brightness = max(nDot1, 0.2);
	vec3 diffuse = brightness * lightColour;

	vec3 unitVectorToCamera = normalize(toCameraVector);
	vec3 lightDirection = -unitLightVector;
	vec3 reflectedLightDuration = reflect(lightDirection, unitNormal);

	float specularFactor = dot(reflectedLightDuration, unitVectorToCamera);
	specularFactor = max(specularFactor, 0);
	float dampedFactor = pow(specularFactor, shineDamper);
	vec3 finalSpecular = dampedFactor * reflectivity * lightColour;

	vec4 textureColour = texture(textureSampler, texCoords);

	if (textureColour.a < 0.5)
		discard;

	returnColor = vec4(diffuse, 1.0) * textureColour + vec4(finalSpecular, 1);returnColor;
	returnColor = mix(vec4(skyColour, 1), returnColor, visibility);
}