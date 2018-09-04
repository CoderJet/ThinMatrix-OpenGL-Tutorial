#include "stdafx.h"

#include "ModelTexture.h"

ModelTexture::ModelTexture(GLuint id)
{
	m_texture_id = id;
}

GLuint ModelTexture::getID()
{
	return m_texture_id;
}
