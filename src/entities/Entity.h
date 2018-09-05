#pragma once
// Local includes.
#include "models/TexturedModel.h"

class Entity
{
public:
	Entity(TexturedModel& model, glm::vec3 position, glm::vec3 rotation, GLfloat scale);

	void increasePosition(GLfloat dx, GLfloat dy, GLfloat dz);

	void increaseRotation(GLfloat dx, GLfloat dy, GLfloat dz);

	TexturedModel getModel();

	glm::vec3 getPosition();

	glm::vec3 getRotation();

	GLfloat getScale();

private:
	TexturedModel		m_model;
	glm::vec3			m_position;
	glm::vec3			m_rotation;
	GLfloat				m_scale;
};

