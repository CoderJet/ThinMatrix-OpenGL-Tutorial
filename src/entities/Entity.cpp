#include "stdafx.h"

#include "Entity.h"

Entity::Entity(TexturedModel model, glm::vec3 position, GLfloat rotX, GLfloat rotY, GLfloat rotZ, GLfloat scale)
	: m_model(model)
	, m_position(position)
	, m_rot_x(rotX)
	, m_rot_y(rotY)
	, m_rot_z(rotZ)
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
	m_rot_x += dx;
	m_rot_y += dy;
	m_rot_z += dz;
}

TexturedModel Entity::getModel()
{
	return m_model;
}

glm::vec3 Entity::getPosition()
{
	return m_position;
}

GLfloat Entity::getRotationX()
{
	return m_rot_x;
}

GLfloat Entity::getRotationY()
{
	return m_rot_y;
}

GLfloat Entity::getRotationZ()
{
	return m_rot_z;
}

GLfloat Entity::getScale()
{
	return m_scale;
}
