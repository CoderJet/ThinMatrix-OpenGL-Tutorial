#pragma once

class Camera
{
public:		
	Camera();

	void move();

	glm::vec3 getPosition();

	GLfloat getPitch();

	GLfloat getYaw();

	GLfloat getRoll();

	void setPosition(glm::vec3 value);

	void setPitch(GLfloat value);

	void setYaw(GLfloat value);

	void setRoll(GLfloat value);

private:
	glm::vec3			m_position;
	GLfloat				m_pitch;
	GLfloat				m_yaw;
	GLfloat				m_roll;
};

