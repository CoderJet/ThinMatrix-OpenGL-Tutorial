// Precompiled header.
#include "stdafx.h"
// Header include.
#include "Camera.h"
#include "render-engine/DisplayManager.h"

Camera::Camera()
	: m_position(0, 0, 0)
	, m_pitch()
	, m_yaw(135)
	, m_roll()
{
}

void Camera::move()
{
	if (DisplayManager::instance().hasFocus())
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_yaw -= 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_yaw += 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_pitch -= 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_pitch += 1;
		}
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

void Camera::setPosition(glm::vec3 value)
{
	m_position = value;
}

void Camera::setPitch(GLfloat value)
{
	m_pitch = value;
}

void Camera::setYaw(GLfloat value)
{
	m_yaw = value;
}

void Camera::setRoll(GLfloat value)
{
	m_roll = value;
}
