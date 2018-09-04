#pragma once

#include "models/TexturedModel.h"

class Entity
{
public:
	Entity(TexturedModel model, glm::vec3 position, GLfloat rotX, GLfloat rotY, GLfloat rotZ, GLfloat scale);

	void increasePosition(GLfloat dx, GLfloat dy, GLfloat dz);

	void increaseRotation(GLfloat dx, GLfloat dy, GLfloat dz);

	TexturedModel getModel();

	glm::vec3 getPosition();

	GLfloat getRotationX();

	GLfloat getRotationY();

	GLfloat getRotationZ();

	GLfloat getScale();

private:
	TexturedModel		m_model;
	glm::vec3			m_position;
	GLfloat				m_rot_x;
	GLfloat				m_rot_y;
	GLfloat				m_rot_z;
	GLfloat				m_scale;
};

