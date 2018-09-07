#pragma once

#include "shaders/TerrainShader.h"

class Terrain;

class TerrainRenderer
{
public:
	TerrainRenderer(TerrainShader& shader, glm::mat4 projectionMatrix);

	void render(std::vector<Terrain>& terrains);

	void prepareTerrain(Terrain& terrain);

	void unbindTexturedModel();

	void loadModelMatrix(Terrain& entity);

private:
	TerrainShader			m_shader;
};

