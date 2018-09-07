// Precompiled header.
#include "stdafx.h"
// Header include.
#include "TexturedModel.h"

TexturedModel::TexturedModel(RawModel& model, ModelTexture& texture)
	: m_raw_model(model)
	, m_texture(texture)
{
}

RawModel TexturedModel::getRawModel() const
{
	return m_raw_model;
}

ModelTexture TexturedModel::getTexture() const
{
	return m_texture;
}