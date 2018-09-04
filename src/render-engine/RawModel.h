#pragma once

class RawModel
{
public:
	RawModel(GLuint vaoID, GLuint vertexCount);

	GLuint getVaoID();

	GLuint getVertexCount();

private:
	GLuint		m_vao_id;
	GLuint		m_vertex_count;
};

