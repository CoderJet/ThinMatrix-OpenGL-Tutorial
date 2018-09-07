// Precompiled header.
#include "stdafx.h"
// Header include.
#include "TerrainRenderer.h"
// Local includes.
#include "terrains/Terrain.h"
#include "toolbox/Maths.h"

TerrainRenderer::TerrainRenderer(TerrainShader& shader, glm::mat4 projectionMatrix)
	: m_shader(shader)
{
	m_shader.start();
	m_shader.loadProjectionMatrix(projectionMatrix);
	m_shader.stop();
}

void TerrainRenderer::render(std::vector<Terrain>& terrains)
{
	for (auto& terrain : terrains)
	{
		prepareTerrain(terrain);
		loadModelMatrix(terrain);
		glDrawElements(GL_TRIANGLES, terrain.getRawModel().getVertexCount(), GL_UNSIGNED_INT, 0);
		unbindTexturedModel();
	}
}

void TerrainRenderer::prepareTerrain(Terrain& terrain)
{
	// Get the raw model from within the textured model.
	RawModel rawModel(terrain.getRawModel());
	// Push the current models details out into a VAO so it can be rendered.
	glBindVertexArray(rawModel.getVaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	ModelTexture texture = terrain.getTexture();
	m_shader.loadShineVariables(texture.getShineDamper(), texture.getReflectivity());

	// Render the entity to the screen.
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, terrain.getTexture().getID());
}

void TerrainRenderer::unbindTexturedModel()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
}

void TerrainRenderer::loadModelMatrix(Terrain& terrain)
{
	// Get the entities current transformtion details so we can pass it to the shader.
	glm::mat4 transformationMatrix(maths::createTransformationMatrix(
		glm::vec3(terrain.getX(), 0, terrain.getZ()),
		glm::vec3(0, 0, 0),
		1)
	);
	// Update the shader so objects can move.
	m_shader.loadTransformationMatrix(transformationMatrix);
}
