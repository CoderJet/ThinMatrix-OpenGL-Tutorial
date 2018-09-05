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
#include "camera/Camera.h"

std::vector<GLfloat>  vertices {
	-0.5f,0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f,0.5f,-0.5f,

	-0.5f,0.5f,0.5f,
	-0.5f,-0.5f,0.5f,
	0.5f,-0.5f,0.5f,
	0.5f,0.5f,0.5f,

	0.5f,0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,0.5f,
	0.5f,0.5f,0.5f,

	-0.5f,0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f,-0.5f,0.5f,
	-0.5f,0.5f,0.5f,

	-0.5f,0.5f,0.5f,
	-0.5f,0.5f,-0.5f,
	0.5f,0.5f,-0.5f,
	0.5f,0.5f,0.5f,

	-0.5f,-0.5f,0.5f,
	-0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,0.5f

};

std::vector<GLfloat>  textureCoords {

	0,0,
	0,1,
	1,1,
	1,0,
	0,0,
	0,1,
	1,1,
	1,0,
	0,0,
	0,1,
	1,1,
	1,0,
	0,0,
	0,1,
	1,1,
	1,0,
	0,0,
	0,1,
	1,1,
	1,0,
	0,0,
	0,1,
	1,1,
	1,0


};

std::vector<GLuint>  indices {
	0,1,3,
	3,1,2,
	4,5,7,
	7,5,6,
	8,9,11,
	11,9,10,
	12,13,15,
	15,13,14,
	16,17,19,
	19,17,18,
	20,21,23,
	23,21,22

};

int main()
{
	DisplayManager::instance().createDisplay();

	StaticShader shader;

	Loader loader;
	Renderer renderer(shader);
	RawModel model(loader.loadToVAO(vertices, textureCoords, indices));
	ModelTexture texture(loader.loadTexture("awesomeface.png"));
	TexturedModel texturedModel(model, texture);
	Entity entity(texturedModel, glm::vec3(0, 0, -5), glm::vec3(0, 0, 0), 1);
	
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
		entity.increaseRotation(1, 1, 0);
		camera.move();
		renderer.prepare();
		shader.start();
		shader.loadViewMatrix(camera);
		renderer.render(entity, shader);
		shader.stop();

		DisplayManager::instance().updateDispaly();
	}
	shader.cleanUp();
	loader.cleanUp();

    return EXIT_SUCCESS;
}

