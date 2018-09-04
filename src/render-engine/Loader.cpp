#include "stdafx.h"

#include "Loader.h"

Loader::Loader()
	: m_vaos()
	, m_vbos()
{
}

RawModel Loader::loadToVAO(std::vector<GLfloat> positions, std::vector<GLuint> indices)
{
	GLuint vaoID = createVAO();
	bindIndicesBuffer(indices);
	storeDataInAttributeList(0, positions);
	unbindVAO();

	return RawModel(vaoID, indices.size());
}

void Loader::cleanUp()
{
	for (auto& vao : m_vaos)
	{
		glDeleteVertexArrays(1, &vao);
	}

	for (auto& vbo : m_vbos)
	{
		glDeleteBuffers(1, &vbo);
	}
}

GLuint Loader::createVAO()
{
	GLuint vaoID;
	glGenVertexArrays(1, &vaoID);
	m_vaos.push_back(vaoID);
	glBindVertexArray(vaoID);

	return vaoID;
}

void Loader::storeDataInAttributeList(GLuint attNumber, std::vector<GLfloat> data)
{
	GLuint vboID;
	GLsizei size = data.size() * sizeof(data[0]);

	glGenBuffers(1, &vboID);
	m_vbos.push_back(vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(attNumber, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVAO()
{
	glBindVertexArray(0);
}

void Loader::bindIndicesBuffer(std::vector<GLuint> indices)
{
	GLuint vboID;
	GLsizei size = indices.size() * sizeof(indices[0]);

	glGenBuffers(1, &vboID);
	m_vbos.push_back(vboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &indices[0], GL_STATIC_DRAW);
}
