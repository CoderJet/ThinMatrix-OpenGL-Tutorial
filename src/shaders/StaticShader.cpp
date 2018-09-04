#include "stdafx.h"
#include "StaticShader.h"

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
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix)
{
	this->loadMatrix(m_transformation_matrix_id, matrix);
}
