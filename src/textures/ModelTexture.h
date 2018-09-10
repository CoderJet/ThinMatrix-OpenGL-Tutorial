#pragma once

class ModelTexture
{
public:
	ModelTexture(GLuint id);

	bool hasTransparency();

	bool useFakeLighting();

	GLuint getID();

	GLfloat getShineDamper();

	GLfloat getReflectivity();

	void setShineDamper(GLfloat shineDamper);

	void setReflectivity(GLfloat reflectivity);

	void setHasTransparency(bool value);

	void setUseFakeLighting(bool value);

private:
	GLuint			m_texture_id;
	GLfloat			m_shine_damper;
	GLfloat			m_reflectivity;

	bool			m_has_transparency;
	bool			m_use_fake_lighting;
};

