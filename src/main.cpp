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

int main()
{
	DisplayManager::instance().createDisplay();

	Loader loader;	
	RawModel model(obj::loader::loadObjModel("Cube.obj", loader));
	ModelTexture texture(loader.loadTexture("Cube.png"));
	ModelTexture terrainTexture(loader.loadTexture("White.png"));
	
	texture.setShineDamper(10);
	texture.setReflectivity(1);

	terrainTexture.setShineDamper(10);
	terrainTexture.setReflectivity(1);

	TexturedModel texturedModel(model, texture);
	Entity entity(texturedModel, glm::vec3(0, 0, -25), glm::vec3(0, 0, 0), 1);
	
	Terrain terrain1(1, 1, loader, terrainTexture);
	//Terrain terrain2(-1, -1, loader, terrainTexture);
	
	Light light(glm::vec3(-50, 0, -10), glm::vec3(1, 1, 1));
	Camera camera;

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
		entity.increaseRotation(0, 1, 0);
		camera.move();

		renderer.processTerrains(terrain1);
		//renderer.processTerrains(terrain2);
		renderer.processEntity(entity);
		renderer.render(light, camera);

		DisplayManager::instance().updateDispaly();
	}
	renderer.cleanUp();
	loader.cleanUp();

    return EXIT_SUCCESS;
}

