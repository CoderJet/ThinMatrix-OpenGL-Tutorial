#pragma once
// Local includes.
#include "shaders/StaticShader.h"

class Entity;
class StaticShader;
class TexturedModel;

class EntityRenderer
{
public:
	EntityRenderer(StaticShader& shader, glm::mat4 projectionMatrix);
	
	void render(std::map<TexturedModel, std::vector<Entity>>& entities);

	void prepareTexturedModel(TexturedModel model);

	void unbindTexturedModel();

	void prepareInstance(Entity entity);

private:
	StaticShader			m_shader;
};

