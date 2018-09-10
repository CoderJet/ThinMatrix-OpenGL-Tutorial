#pragma once

#include "models/RawModel.h"
#include "textures/ModelTexture.h"

class Loader;

class Terrain
{
public:
	Terrain(GLuint gridX, GLuint gridZ, Loader& loader, ModelTexture& texture);

	RawModel generateTerrain(Loader& loader);

	GLfloat getX();

	GLfloat getZ();

	RawModel getRawModel();

	ModelTexture getTexture();
	
private:
	const GLfloat			SIZE{ 800 };
	const GLuint			VERTEX_COUNT{ 128 };

	GLfloat					m_x;
	GLfloat					m_z;

	RawModel				m_model;
	ModelTexture			m_texture;
};
