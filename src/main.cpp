// Precompiled header.
#include "stdafx.h"

#include "render-engine/DisplayManager.h"
#include "render-engine/Loader.h"
#include "render-engine/Renderer.h"
#include "models/RawModel.h"
#include "models/TexturedModel.h"
#include "textures/ModelTexture.h"
#include "shaders/StaticShader.h"
#include "entities/Entity.h"
#include "entities/Light.h"
#include "camera/Camera.h"

#include "render-engine/OBJLoader.h"

int main()
{
	DisplayManager::instance().createDisplay();

	StaticShader shader;

	Loader loader;
	Renderer renderer(shader);
	RawModel model(obj::loader::loadObjModel("Dragon.obj", loader));
	ModelTexture texture(loader.loadTexture("White.png"));
	texture.setShineDamper(10);
	texture.setReflectivity(1);
	TexturedModel texturedModel(model, texture);
	Entity entity(texturedModel, glm::vec3(0, 0, -25), glm::vec3(0, 0, 0), 1);
	Light light(glm::vec3(0, 0, -10), glm::vec3(1, 1, 1));
	Camera camera;

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
		renderer.prepare();
		shader.start();
		shader.loadLight(light);
		shader.loadViewMatrix(camera);
		renderer.render(entity, shader);
		shader.stop();

		DisplayManager::instance().updateDispaly();
	}
	shader.cleanUp();
	loader.cleanUp();

    return EXIT_SUCCESS;
}

