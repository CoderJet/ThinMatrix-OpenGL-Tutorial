// Precompiled header.
#include "stdafx.h"
// Header include.
#include "MasterRenderer.h"
// Local includes.
#include "camera/Camera.h"
#include "entities/Light.h"

MasterRenderer::MasterRenderer()
	: m_shader()
	, m_renderer(m_shader)
	, m_entities()
{
}

void MasterRenderer::render(Light& sun, Camera& camera)
{
	m_renderer.prepare();
	m_shader.start();
	m_shader.loadLight(sun);
	m_shader.loadViewMatrix(camera);
	m_renderer.render(m_entities);
	m_shader.stop();
	m_entities.clear();
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
}
