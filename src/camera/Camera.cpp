// Precompiled header.
#include "stdafx.h"
// Header include.
#include "Camera.h"

Camera::Camera()
	: m_position(0, 0, 0)
	, m_pitch()
	, m_yaw()
	, m_roll()
{
}

void Camera::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_position.z -= 0.2f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_position.z += 0.2f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_position.x -= 0.2f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_position.x += 0.2f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_position.y += 0.2f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		m_position.y -= 0.2f;
	}
}

glm::vec3 Camera::getPosition()
{
	return m_position;
}

GLfloat Camera::getPitch()
{
	return m_pitch;
}

GLfloat Camera::getYaw()
{
	return m_yaw;
}

GLfloat Camera::getRoll()
{
	return m_roll;
}