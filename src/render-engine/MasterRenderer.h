#pragma once
// Local includes.
#include "Renderer.h"
#include "entities/Entity.h"
#include "models/TexturedModel.h"
#include "shaders/StaticShader.h"

class Camera;
class Light;

class MasterRenderer
{
public:
	MasterRenderer();

	void render(Light& sun, Camera& camera);

	void processEntity(Entity& entity);

	void cleanUp();

private:
	StaticShader														m_shader;
	Renderer															m_renderer;

	std::map<TexturedModel, std::vector<Entity>>		m_entities;
};

