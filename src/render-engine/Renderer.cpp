#include "stdafx.h"

#include "Renderer.h"

#include "entities/Entity.h"
#include "shaders/StaticShader.h"
#include "toolbox/Maths.h"
#include "config/Config.h"

Renderer::Renderer(StaticShader& shader)
{
	createProjectionMatrix();
	shader.start();
	shader.loadProjectionMatrix(m_projection_matrix);
	shader.stop();
}

void Renderer::prepare()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(Entity entity, StaticShader& shader)
{
	TexturedModel texturedModel(entity.getModel());

	RawModel model(texturedModel.getRawModel());
	glBindVertexArray(model.getVaoID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glm::mat4 transformationMatrix(maths::createTransformationMatrix(
		entity.getPosition(),
		entity.getRotationX(),
		entity.getRotationY(),
		entity.getRotationZ(),
		entity.getScale())
	);
	shader.loadTransformationMatrix(transformationMatrix);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturedModel.getTexture().getID());
	glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
}

void Renderer::createProjectionMatrix()
{
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
