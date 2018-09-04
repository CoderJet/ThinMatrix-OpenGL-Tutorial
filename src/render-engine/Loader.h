#pragma once

#include "models/RawModel.h"

class Loader
{
public:
	Loader();

	RawModel loadToVAO(std::vector<GLfloat> positions, std::vector<GLfloat> textureCoords, std::vector<GLuint> indices);

	GLuint loadTexture(std::string fileName);

	void cleanUp();

private:
	GLuint createVAO();

	void storeDataInAttributeList(GLuint attNumber, GLuint coordinateSize, std::vector<GLfloat> data);

	void unbindVAO();

	void bindIndicesBuffer(std::vector<GLuint> indices);

private:
	std::vector<GLuint>		m_vaos;
	std::vector<GLuint>		m_vbos;
	std::vector<GLuint>		m_textures;
};

