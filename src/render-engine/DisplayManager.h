#pragma once

class DisplayManager
{
public:
	static DisplayManager& instance();

	void createDisplay();

	void updateDispaly();

	void closeDisplay();

	bool isRunning();

	bool pollEvents(sf::Event& event);

private:
	DisplayManager();

	DisplayManager(DisplayManager const&) = delete;		// Don't Implement.

	void operator=(DisplayManager const&) = delete;		// Don't implement

private:
	sf::Window				m_window;
	sf::ContextSettings		m_context_settings;

	bool					m_initialised;
};

