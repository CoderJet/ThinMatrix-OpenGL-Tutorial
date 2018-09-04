#pragma once

#include "RawModel.h"

class Loader
{
public:
	Loader();

	RawModel loadToVAO(std::vector<GLfloat> positions);

	void cleanUp();

private:
	GLuint createVAO();

	void storeDataInAttributeList(GLuint attNumber, std::vector<GLfloat> data);

	void unbindVAO();

private:
	std::vector<GLuint> m_vaos;
	std::vector<GLuint> m_vbos;
};

