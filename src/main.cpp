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
	 0.5f,  0.5f, 0.0f
};

std::vector<GLuint> indices
{
	0, 1, 3,	// Top left triangle (V0, V1, V3)
	3, 1, 2		// Bottom right triangle (V3, V1, V2)
};

int main()
{
	DisplayManager::instance().createDisplay();

	Loader loader;
	Renderer renderer;
	RawModel model(loader.loadToVAO(vertices, indices));

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

