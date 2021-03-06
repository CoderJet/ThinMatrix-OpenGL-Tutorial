// Precompiled header.
#include "stdafx.h"

#include "render-engine/DisplayManager.h"
#include "render-engine/Loader.h"
#include "render-engine/EntityRenderer.h"
#include "models/RawModel.h"
#include "models/TexturedModel.h"
#include "textures/ModelTexture.h"
#include "shaders/StaticShader.h"
#include "entities/Entity.h"
#include "entities/Light.h"
#include "camera/Camera.h"

#include "render-engine/OBJLoader.h"
#include "render-engine/MasterRenderer.h"

#include "terrains/Terrain.h"

#include "toolbox/Random.h"

int main()
{
	DisplayManager::instance().createDisplay();

	Loader loader;	
	RawModel treeModel(obj::loader::loadObjModel("tree.obj", loader));
	RawModel grassModel(obj::loader::loadObjModel("grassModel.obj", loader));
	RawModel fernModel(obj::loader::loadObjModel("fern.obj", loader));

	ModelTexture treeTexture(loader.loadTexture("tree.png"));
	ModelTexture grassTexture(loader.loadTexture("grassTexture.png"));
	grassTexture.setHasTransparency(true);
	grassTexture.setUseFakeLighting(true);
	ModelTexture fernTexture(loader.loadTexture("fern.png"));
	fernTexture.setHasTransparency(true);
	ModelTexture terrainTexture(loader.loadTexture("grass.png"));
	
	treeTexture.setShineDamper(10);
	treeTexture.setReflectivity(1);

	terrainTexture.setShineDamper(10);
	terrainTexture.setReflectivity(0);

	TexturedModel texturedTreeModel(treeModel, treeTexture);
	TexturedModel texturedGrassModel(grassModel, grassTexture);
	TexturedModel texturedFernModel(fernModel, fernTexture);

	std::vector<Entity> trees;
	std::vector<Entity> grass;
	std::vector<Entity> ferns;
	Random rand;
	
	for (GLuint i = 0; i < 50; i++)
	{
		GLfloat x(rand.randomFloat(0, 800));
		GLfloat y = 0;
		GLfloat z(rand.randomFloat(0, 800));

		trees.push_back(Entity(texturedTreeModel, glm::vec3(x, y, z), glm::vec3(0, 0, 0), 7));
	}

	for (GLuint i = 0; i < 500; i++)
	{
		GLfloat x(rand.randomFloat(0, 800));
		GLfloat y = 0;
		GLfloat z(rand.randomFloat(0, 800));

		grass.push_back(Entity(texturedGrassModel, glm::vec3(x, y, z), glm::vec3(0, 0, 0), 2));
	}

	for (GLuint i = 0; i < 500; i++)
	{
		GLfloat x(rand.randomFloat(0, 800));
		GLfloat y = 0;
		GLfloat z(rand.randomFloat(0, 800));

		ferns.push_back(Entity(texturedFernModel, glm::vec3(x, y, z), glm::vec3(0, 0, 0), 1));
	}



	Terrain terrain1(0, 0, loader, terrainTexture);
	
	Light light(glm::vec3(0, 1000, 0), glm::vec3(1, 1, 1));
	Camera camera;
	camera.setPosition(glm::vec3(400, 5, 400));

	MasterRenderer renderer;

	sf::Event event;
	
	while (DisplayManager::instance().isRunning())
	{
		while (DisplayManager::instance().pollEvents(event))
		{
			if (event.type == sf::Event::Closed
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				DisplayManager::instance().closeDisplay();
			}
		}
		camera.move();

		renderer.processTerrains(terrain1);

		for (GLuint i = 0; i < 50; i++)
		{
			renderer.processEntity(trees[i]);
		}

		for (GLuint i = 0; i < 500; i++)
		{
			renderer.processEntity(grass[i]);
			renderer.processEntity(ferns[i]);
		}

		renderer.render(light, camera);

		DisplayManager::instance().updateDispaly();
	}
	renderer.cleanUp();
	loader.cleanUp();

    return EXIT_SUCCESS;
}

