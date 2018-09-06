// Precompiled header.
#include "stdafx.h"
// Header include.
#include "ModelTexture.h"

ModelTexture::ModelTexture(GLuint id)
	: m_texture_id(id)
	, m_shine_damper(1)
	, m_reflectivity(0)
{
}

GLuint ModelTexture::getID()
{
	return m_texture_id;
}

GLfloat ModelTexture::getShineDamper()
{
	return m_shine_damper;
}

GLfloat ModelTexture::getReflectivity()
{
	return m_reflectivity;
}

void ModelTexture::setShineDamper(GLfloat shineDamper)
{
	m_shine_damper = shineDamper;
}

void ModelTexture::setReflectivity(GLfloat reflectivity)
{
	m_reflectivity = reflectivity;
}
