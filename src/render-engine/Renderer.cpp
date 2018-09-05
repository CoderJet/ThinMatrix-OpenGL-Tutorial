// Precompiled header.
#include "stdafx.h"
// Header include.
#include "Renderer.h"
// Local cincludes.
#include "config/Config.h"
#include "entities/Entity.h"
#include "shaders/StaticShader.h"
#include "toolbox/Maths.h"

Renderer::Renderer(StaticShader& shader)
{
	createProjectionMatrix();
	shader.start();
	shader.loadProjectionMatrix(m_projection_matrix);
	shader.stop();
}

void Renderer::prepare()
{
	// Make sure we enable to depth buffer, in order for items
	// not to draw ontop of one another.
	glEnable(GL_DEPTH_TEST);
	// Clear the screen with a default colour.
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(Entity& entity, StaticShader& shader)
{
	// Get the textured model from our passed entity.
	TexturedModel texturedModel(entity.getModel());
	// Get the raw model from within the textured model.
	RawModel model(texturedModel.getRawModel());
	// Push the current models details out into a VAO so it can be rendered.
	glBindVertexArray(model.getVaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	// Get the entities current transformtion details so we can pass it to the shader.
	glm::mat4 transformationMatrix(maths::createTransformationMatrix(
		entity.getPosition(),
		entity.getRotation(),
		entity.getScale())
	);
	// Update the shader so objects can move.
	shader.loadTransformationMatrix(transformationMatrix);
	// Render the entity to the screen.
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturedModel.getTexture().getID());
	glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}

void Renderer::createProjectionMatrix()
{
	// Initialise our view matrix once, as this won't be changing.
	GLfloat aspectRatio((float)config::WIDTH / (float)config::HEIGHT);
	GLfloat yScale((1.0f / tan(glm::radians(FOV / 2.0f))) * aspectRatio);
	GLfloat xScale(yScale / aspectRatio);
	GLfloat frustumLength(FAR_PLANE - NEAR_PLANE);

	m_projection_matrix = glm::mat4(1.0f);
	m_projection_matrix[0][0] = xScale;
	m_projection_matrix[1][1] = yScale;
	m_projection_matrix[2][2] = -((FAR_PLANE + NEAR_PLANE) / frustumLength);
	m_projection_matrix[2][3] = -1.0f;
	m_projection_matrix[3][2] = -((2 * NEAR_PLANE * FAR_PLANE) / frustumLength);
	m_projection_matrix[3][3] = 0;
}
