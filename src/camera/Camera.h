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

private:
	glm::vec3			m_position;
	GLfloat				m_pitch;
	GLfloat				m_yaw;
	GLfloat				m_roll;
};

