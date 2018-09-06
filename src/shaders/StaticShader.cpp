// Precompiled header.
#include "stdafx.h"
// Header include.
#include "StaticShader.h"
// Local includes.
#include "camera/Camera.h"
#include "entities/Light.h"
#include "toolbox/Maths.h"

StaticShader::StaticShader()
	: Shader("./src/shaders/Basic.vert", "./src/shaders/Basic.frag")
{
}

void StaticShader::bindAttributes()
{
	// Associate each 'in' variable with the VAO indexes.
	this->bindAttribute(0, "position");
	this->bindAttribute(1, "textureCoords");
	this->bindAttribute(2, "normal");
}

void StaticShader::getAllUniformLocations()
{
	// Get all the ids for all the unfiforms for the current vertex and fragment shaders.
	m_transformation_matrix_id = this->getUniformLocation("transformationMatrix");
	m_projection_matrix_id = this->getUniformLocation("projectionMatrix");
	m_view_matrix_id = this->getUniformLocation("viewMatrix");
	m_light_position_id = this->getUniformLocation("lightPosition");
	m_light_colour_id = this->getUniformLocation("lightColour");
	m_shine_damper_id = this->getUniformLocation("shineDamper");
	m_reflectivity_id = this->getUniformLocation("reflectivity");
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix)
{
	this->loadMatrix(m_transformation_matrix_id, matrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4 projection)
{
	this->loadMatrix(m_projection_matrix_id, projection);
}

void StaticShader::loadViewMatrix(Camera& camera)
{
	this->loadMatrix(m_view_matrix_id, maths::createViewMatrix(camera));
}

void StaticShader::loadLight(Light& light)
{
	this->loadVector(m_light_position_id, light.getPosition());
	this->loadVector(m_light_colour_id, light.getColour());
}

void StaticShader::loadShineVariables(float damper, float reflectivity)
{
	this->loadFloat(m_shine_damper_id, damper);
	this->loadFloat(m_reflectivity_id, reflectivity);
}
