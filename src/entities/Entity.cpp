// Precompiled header.
#include "stdafx.h"
// Header include.
#include "Entity.h"

Entity::Entity(TexturedModel& model, glm::vec3 position, glm::vec3 rotation, GLfloat scale)
	: m_model(model)
	, m_position(position)
	, m_rotation(rotation)
	, m_scale(scale)
{
}

void Entity::increasePosition(GLfloat dx, GLfloat dy, GLfloat dz)
{
	m_position.x += dx;
	m_position.y += dy;
	m_position.z += dz;
}

void Entity::increaseRotation(GLfloat dx, GLfloat dy, GLfloat dz)
{
	m_rotation.x += dx;
	m_rotation.y += dy;
	m_rotation.z += dz;
}

TexturedModel Entity::getModel()
{
	return m_model;
}

glm::vec3 Entity::getPosition()
{
	return m_position;
}

glm::vec3 Entity::getRotation()
{
	return m_rotation;
}

GLfloat Entity::getScale()
{
	return m_scale;
}
