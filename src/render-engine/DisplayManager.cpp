#include "stdafx.h"

#include "DisplayManager.h"

#include "config/Config.h"

DisplayManager::DisplayManager()
	: m_window()
	, m_context_settings()
	, m_initialised{ false }
{
	m_context_settings.depthBits = 24;
	m_context_settings.stencilBits = 8;
	m_context_settings.antialiasingLevel = 4;
	m_context_settings.majorVersion = 3;
	m_context_settings.minorVersion = 3;
	m_context_settings.attributeFlags = sf::ContextSettings::Core;
}

DisplayManager & DisplayManager::instance()
{
	static DisplayManager instance;
	return instance;
}

void DisplayManager::createDisplay()
{
	if (!m_initialised)
	{
		m_window.create(sf::VideoMode(config::WIDTH, config::HEIGHT), "Our First Display!", sf::Style::Default, m_context_settings);
		m_window.setFramerateLimit(config::MAX_FPS);
		m_window.setVerticalSyncEnabled(true);

		glViewport(0, 0, config::WIDTH, config::HEIGHT);

		m_initialised = true;
	}
}

void DisplayManager::updateDispaly()
{
	m_window.display();
}

void DisplayManager::closeDisplay()
{
	m_window.close();
}

bool DisplayManager::isRunning()
{
	return m_window.isOpen();
}

bool DisplayManager::pollEvents(sf::Event & event)
{
	return m_window.pollEvent(event);
}
