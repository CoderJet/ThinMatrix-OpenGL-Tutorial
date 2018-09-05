// Precompiled header.
#include "stdafx.h"
// Header include.
#include "ModelTexture.h"

ModelTexture::ModelTexture(GLuint id)
{
	m_texture_id = id;
}

GLuint ModelTexture::getID()
{
	return m_texture_id;
}
