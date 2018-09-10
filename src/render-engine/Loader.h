#pragma once

class RawModel;

class Loader
{
public:
	Loader();

	RawModel loadToVAO(std::vector<GLfloat>& positions, std::vector<GLfloat>& textureCoords, std::vector<GLfloat>& normals, std::vector<GLint>& indices);

	GLuint loadTexture(const std::string& fileName);

	void cleanUp();

private:
	GLuint createVAO();

	void storeDataInAttributeList(GLuint index, GLuint vectorSize, std::vector<GLfloat>& data);

	void unbindVAO();

	void bindIndicesBuffer(std::vector<GLint>& indices);

private:
	std::vector<GLuint>		m_vaos;
	std::vector<GLuint>		m_vbos;
	std::vector<GLuint>		m_textures;
};

