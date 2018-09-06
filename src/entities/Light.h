#pragma once

class Light
{
public:
	Light(glm::vec3 position, glm::vec3 colour);

	glm::vec3 getPosition();

	glm::vec3 getColour();

	void setPosition(glm::vec3 position);

	void setColour(glm::vec3 colour);

private:
	glm::vec3			m_position;
	glm::vec3			m_colour;
};
