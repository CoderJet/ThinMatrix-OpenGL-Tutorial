// Precompiled header.
#include "stdafx.h"
// Header include.
#include "TerrainShader.h"
// Local includes.
#include "camera/Camera.h"
#include "entities/Light.h"
#include "toolbox/Maths.h"

TerrainShader::TerrainShader()
	: Shader("./res/shaders/Terrain.vert", "./res/shaders/Terrain.frag")
{
}

void TerrainShader::bindAttributes()
{
	// Associate each 'in' variable with the VAO indexes.
	this->bindAttribute(0, "position");
	this->bindAttribute(1, "textureCoords");
	this->bindAttribute(2, "normal");
}

void TerrainShader::getAllUniformLocations()
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

void TerrainShader::loadTransformationMatrix(glm::mat4 matrix)
{
	this->loadMatrix(m_transformation_matrix_id, matrix);
}

void TerrainShader::loadProjectionMatrix(glm::mat4 projection)
{
	this->loadMatrix(m_projection_matrix_id, projection);
}

void TerrainShader::loadViewMatrix(Camera& camera)
{
	this->loadMatrix(m_view_matrix_id, maths::createViewMatrix(camera));
}

void TerrainShader::loadLight(Light& light)
{
	this->loadVector(m_light_position_id, light.getPosition());
	this->loadVector(m_light_colour_id, light.getColour());
}

void TerrainShader::loadShineVariables(float damper, float reflectivity)
{
	this->loadFloat(m_shine_damper_id, damper);
	this->loadFloat(m_reflectivity_id, reflectivity);
}
