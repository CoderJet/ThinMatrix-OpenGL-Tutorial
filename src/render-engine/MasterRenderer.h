#pragma once
// Local includes.
#include "EntityRenderer.h"
#include "TerrainRenderer.h"
#include "entities/Entity.h"
#include "models/TexturedModel.h"
#include "shaders/StaticShader.h"
#include "shaders/TerrainShader.h"
#include "terrains/Terrain.h"

class Camera;
class Light;

class MasterRenderer
{
public:
	MasterRenderer();

	void prepare();

	void render(Light& sun, Camera& camera);

	void processTerrains(Terrain& terrain);

	void processEntity(Entity& entity);

	void cleanUp();

private:
	glm::mat4 createProjectionMatrix();

private:
	const GLfloat										FOV{ 70.0f };
	const GLfloat										NEAR_PLANE{ 0.1f };
	const GLfloat										FAR_PLANE{ 1000.0f };

	glm::mat4											m_projection_matrix;
	StaticShader										m_shader;
	TerrainShader										m_terrain_shader;
	EntityRenderer										m_renderer;	
	TerrainRenderer										m_terrain_renderer;	

	std::map<TexturedModel, std::vector<Entity>>		m_entities;
	std::vector<Terrain>								m_terrains;
};

