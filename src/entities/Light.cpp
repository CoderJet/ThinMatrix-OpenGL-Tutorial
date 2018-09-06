// Precompiled header.
#include "stdafx.h"
// Header include.
#include "Light.h"

Light::Light(glm::vec3 position, glm::vec3 colour)
	: m_position(position)
	, m_colour(colour)
{

}

glm::vec3 Light::getPosition()
{
	return m_position;
}

glm::vec3 Light::getColour()
{
	return m_colour;
}

void Light::setPosition(glm::vec3 position)
{
	m_position = position;
}

void Light::setColour(glm::vec3 colour)
{
	m_colour = colour;
}
