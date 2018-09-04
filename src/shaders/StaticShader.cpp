#include "stdafx.h"

#include "StaticShader.h"

#include "toolbox/Maths.h"

StaticShader::StaticShader()
	: Shader("./src/shaders/Basic.vert", "./src/shaders/Basic.frag")
{
}

void StaticShader::bindAttributes()
{
	this->bindAttribute(0, "position");
	this->bindAttribute(1, "textureCoords");
}

void StaticShader::getAllUniformLocations()
{
	m_transformation_matrix_id = this->getUniformLocation("transformationMatrix");
	m_projection_matrix_id = this->getUniformLocation("projectionMatrix");
	m_view_matrix_id = this->getUniformLocation("viewMatrix");
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix)
{
	this->loadMatrix(m_transformation_matrix_id, matrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4 projection)
{
	this->loadMatrix(m_projection_matrix_id, projection);
}

void StaticShader::loadViewMatrix(Camera camera)
{
	this->loadMatrix(m_view_matrix_id, maths::createViewMatrix(camera));
}
