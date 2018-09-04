#include "stdafx.h"

#include "Loader.h"

Loader::Loader()
	: m_vaos()
	, m_vbos()
{
}

RawModel Loader::loadToVAO(std::vector<GLfloat> positions, std::vector<GLfloat> textureCoords, std::vector<GLuint> indices)
{
	GLuint vaoID = createVAO();
	bindIndicesBuffer(indices);
	storeDataInAttributeList(0, 3, positions);
	storeDataInAttributeList(1, 2, textureCoords);
	unbindVAO();

	return RawModel(vaoID, indices.size());
}

GLuint Loader::loadTexture(std::string fileName)
{
	sf::Image image;
	image.loadFromFile("./res/textures/" + fileName);

	GLuint textureID;
	glGenTextures(1, &textureID);
	m_textures.push_back(textureID);
	
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RGBA, 
		image.getSize().x, 
		image.getSize().y, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, 
		image.getPixelsPtr());
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	return textureID;
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

	for (auto& texture : m_textures)
	{
		glDeleteTextures(1, &texture);
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

void Loader::storeDataInAttributeList(GLuint attNumber, GLuint coordinateSize, std::vector<GLfloat> data)
{
	GLuint vboID;
	GLsizei size = data.size() * sizeof(data[0]);

	glGenBuffers(1, &vboID);
	m_vbos.push_back(vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(attNumber, coordinateSize, GL_FLOAT, GL_FALSE, 0, 0);
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
