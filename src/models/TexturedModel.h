#pragma once
// Local includes.
#include "RawModel.h"
#include "textures/ModelTexture.h"

class TexturedModel
{
public:
	TexturedModel(RawModel& model, ModelTexture& texture);
	
	RawModel getRawModel() const;

	ModelTexture getTexture() const;

	bool operator < (const TexturedModel& other) const
	{
		return other.getRawModel().getVaoID() < this->getRawModel().getVaoID();
	}

private:
	RawModel			m_raw_model;
	ModelTexture		m_texture;

	GLuint				m_id;
};
