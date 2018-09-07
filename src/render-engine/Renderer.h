#pragma once
// Local includes.
#include "shaders/StaticShader.h"

class Entity;
class StaticShader;
class TexturedModel;

class Renderer
{
public:
	Renderer(StaticShader& shader);
	
	void prepare();

	void render(const std::map<TexturedModel, std::vector<Entity>>& entities);

	void prepareTexturedModel(TexturedModel model);

	void unbindTexturedModel();

	void prepareInstance(Entity entity);

private:
	void createProjectionMatrix();

private:
	const GLfloat			FOV{ 70.0f };
	const GLfloat			NEAR_PLANE{ 0.1f };
	const GLfloat			FAR_PLANE{ 1000.0f };

	glm::mat4				m_projection_matrix;
	StaticShader			m_shader;
};

