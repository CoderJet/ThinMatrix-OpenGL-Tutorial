// Precompiled header.
#include "stdafx.h"
// Header include.
#include "MasterRenderer.h"
// Local includes.
#include "camera/Camera.h"
#include "config/Config.h"
#include "entities/Light.h"

MasterRenderer::MasterRenderer()
	: m_projection_matrix(createProjectionMatrix())
	, m_shader()
	, m_terrain_shader()
	, m_renderer(m_shader, m_projection_matrix)
	, m_terrain_renderer(m_terrain_shader, m_projection_matrix)
	, m_entities()
	, m_terrains()
{
}

void MasterRenderer::prepare()
{
	// Make sure we enable to depth buffer, in order for items
	// not to draw ontop of one another.
	glEnable(GL_DEPTH_TEST);
	// Clear the screen with a default colour.
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MasterRenderer::render(Light& sun, Camera& camera)
{
	prepare();
	
	m_shader.start();
	m_shader.loadLight(sun);
	m_shader.loadViewMatrix(camera);
	m_renderer.render(m_entities);
	m_shader.stop();

	m_terrain_shader.start();
	m_terrain_shader.loadLight(sun);
	m_terrain_shader.loadViewMatrix(camera);
	m_terrain_renderer.render(m_terrains);
	m_terrain_shader.stop();

	m_terrains.clear();
	m_entities.clear();
}

void MasterRenderer::processTerrains(Terrain & terrain)
{
	m_terrains.push_back(terrain);
}

void MasterRenderer::processEntity(Entity & entity)
{
	const TexturedModel model(entity.getModel());

	if (m_entities.count(model))
	{
		m_entities[model].push_back(entity);
	}
	else
	{
		std::vector<Entity> batch;
		batch.push_back(entity);
		m_entities[model] = batch;
	}
}

void MasterRenderer::cleanUp()
{
	m_shader.cleanUp();
	m_terrain_shader.cleanUp();
}

glm::mat4 MasterRenderer::createProjectionMatrix()
{
	return glm::perspective(glm::radians(FOV), (float)config::WIDTH / config::HEIGHT, NEAR_PLANE, FAR_PLANE);
}
