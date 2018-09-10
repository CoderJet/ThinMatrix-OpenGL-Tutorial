// Precompiled header.
#include "stdafx.h"
// Header include.
#include "ModelTexture.h"

ModelTexture::ModelTexture(GLuint id)
	: m_texture_id(id)
	, m_shine_damper(1)
	, m_reflectivity(0)
	, m_has_transparency(false)
{
}

bool ModelTexture::hasTransparency()
{
	return m_has_transparency;
}

bool ModelTexture::useFakeLighting()
{
	return m_use_fake_lighting;
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

void ModelTexture::setHasTransparency(bool value)
{
	m_has_transparency = value;
}

void ModelTexture::setUseFakeLighting(bool value)
{
	m_use_fake_lighting = value;
}
