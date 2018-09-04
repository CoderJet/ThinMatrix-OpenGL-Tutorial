#include "stdafx.h"
#include "RawModel.h"

RawModel::RawModel(GLuint vaoID, GLuint vertexCount)
	: m_vao_id{ vaoID }
	, m_vertex_count{ vertexCount }
{	
}

GLuint RawModel::getVaoID()
{
	return m_vao_id;
}

GLuint RawModel::getVertexCount()
{
	return m_vertex_count;
}
