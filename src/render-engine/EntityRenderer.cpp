// Precompiled header.
#include "stdafx.h"
// Header include.
#include "EntityRenderer.h"
// Local cincludes.
#include "MasterRenderer.h"
#include "config/Config.h"
#include "entities/Entity.h"
#include "models/TexturedModel.h"
#include "toolbox/Maths.h"

EntityRenderer::EntityRenderer(StaticShader& shader, glm::mat4 projectionMatrix)
	: m_shader(shader)
{
	m_shader.start();
	m_shader.loadProjectionMatrix(projectionMatrix);
	m_shader.stop();
}

void EntityRenderer::render(std::map<TexturedModel, std::vector<Entity>>& entities)
{
	for (auto& pair : entities)
	{
		TexturedModel model(pair.first);
		prepareTexturedModel(model);

		for (auto& entity : pair.second)
		{
			prepareInstance(entity);

			glDrawElements(GL_TRIANGLES, model.getRawModel().getVertexCount(), GL_UNSIGNED_INT, 0);
		}
		unbindTexturedModel();
	}
}

void EntityRenderer::prepareTexturedModel(TexturedModel model)
{
	// Get the raw model from within the textured model.
	RawModel rawModel(model.getRawModel());
	// Push the current models details out into a VAO so it can be rendered.
	glBindVertexArray(rawModel.getVaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	ModelTexture texture = model.getTexture();
	if (texture.hasTransparency())
	{
		MasterRenderer::disableCulling();
	}
	m_shader.loadFakeLightingVariable(texture.useFakeLighting());
	m_shader.loadShineVariables(texture.getShineDamper(), texture.getReflectivity());

	// Render the entity to the screen.
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, model.getTexture().getID());
}

void EntityRenderer::unbindTexturedModel()
{
	MasterRenderer::enableCulling();
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
}

void EntityRenderer::prepareInstance(Entity entity)
{
	// Get the entities current transformtion details so we can pass it to the shader.
	glm::mat4 transformationMatrix(maths::createTransformationMatrix(
		entity.getPosition(),
		entity.getRotation(),
		entity.getScale())
	);
	// Update the shader so objects can move.
	m_shader.loadTransformationMatrix(transformationMatrix);
}
