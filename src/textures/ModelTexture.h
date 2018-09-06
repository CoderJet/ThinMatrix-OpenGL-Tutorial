#pragma once

class ModelTexture
{
public:
	ModelTexture(GLuint id);

	GLuint getID();

	GLfloat getShineDamper();

	GLfloat getReflectivity();

	void setShineDamper(GLfloat shineDamper);

	void setReflectivity(GLfloat reflectivity);

private:
	GLuint			m_texture_id;
	GLfloat			m_shine_damper;
	GLfloat			m_reflectivity;
};

