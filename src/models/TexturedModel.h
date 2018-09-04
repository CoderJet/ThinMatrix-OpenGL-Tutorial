#pragma once

#include "RawModel.h"
#include "textures/ModelTexture.h"

class TexturedModel
{
public:
	TexturedModel(RawModel model, ModelTexture texture);

	RawModel getRawModel();

	ModelTexture getTexture();

private:
	RawModel			m_raw_model;
	ModelTexture		m_texture;
};

