#include "stdafx.h"

#include "render-engine/DisplayManager.h"

int main()
{
	DisplayManager::instance().createDisplay();

	sf::Event event;

	while (DisplayManager::instance().isRunning())
	{
		while (DisplayManager::instance().pollEvents(event))
		{
			if (event.type == sf::Event::Closed)
			{
				DisplayManager::instance().closeDisplay();
			}
		}

		DisplayManager::instance().updateDispaly();
	}
    return EXIT_SUCCESS;
}

