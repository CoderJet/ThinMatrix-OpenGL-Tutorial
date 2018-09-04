#include "stdafx.h"

#include "render-engine/DisplayManager.h"
#include "render-engine/Loader.h"
#include "render-engine/Renderer.h"
#include "render-engine/RawModel.h"

std::vector<GLfloat> vertices
{
	-0.5f,  0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.5f,  0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f
};

int main()
{
	DisplayManager::instance().createDisplay();

	Loader loader;
	Renderer renderer;
	RawModel model(loader.loadToVAO(vertices));

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
		renderer.prepare();
		renderer.render(model);

		DisplayManager::instance().updateDispaly();
	}
	loader.cleanUp();

    return EXIT_SUCCESS;
}

