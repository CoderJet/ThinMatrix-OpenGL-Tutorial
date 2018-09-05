#pragma once

class ModelTexture
{
public:
	ModelTexture(GLuint id);

	GLuint getID();
private:
	GLuint		m_texture_id;
};

