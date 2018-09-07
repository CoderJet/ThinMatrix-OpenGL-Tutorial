// Precompiled header.
#include "stdafx.h"
// Header include.
#include "Terrain.h"
// Local includes.
#include "render-engine/Loader.h"

Terrain::Terrain(GLuint gridX, GLuint gridZ, Loader & loader, ModelTexture & texture)
	: m_x(gridX * SIZE)
	, m_z(gridZ * SIZE)
	, m_model(generateTerrain(loader))
	, m_texture(texture)
{
}

RawModel Terrain::generateTerrain(Loader & loader)
{
	int count = VERTEX_COUNT * VERTEX_COUNT;
	
	std::vector<GLfloat> vertices(count * 3);
	std::vector<GLfloat> normals(count * 3);
	std::vector<GLfloat> textures(count * 2);

	std::vector<GLuint> indices(6 * (VERTEX_COUNT - 1) * (VERTEX_COUNT - 1));

	int vertexPointer = 0;

	for (int i = 0; i < VERTEX_COUNT; i++) {
		for (int j = 0; j < VERTEX_COUNT; j++) {
			vertices[vertexPointer * 3] = (float)j / ((float)VERTEX_COUNT - 1) * SIZE;
			vertices[vertexPointer * 3 + 1] = 0;
			vertices[vertexPointer * 3 + 2] = (float)i / ((float)VERTEX_COUNT - 1) * SIZE;
			normals[vertexPointer * 3] = 0;
			normals[vertexPointer * 3 + 1] = 1;
			normals[vertexPointer * 3 + 2] = 0;
			textures[vertexPointer * 2] = (float)j / ((float)VERTEX_COUNT - 1);
			textures[vertexPointer * 2 + 1] = (float)i / ((float)VERTEX_COUNT - 1);
			vertexPointer++;
		}
	}
	int pointer = 0;
	for (int gz = 0; gz < VERTEX_COUNT - 1; gz++) {
		for (int gx = 0; gx < VERTEX_COUNT - 1; gx++) {
			int topLeft = (gz*VERTEX_COUNT) + gx;
			int topRight = topLeft + 1;
			int bottomLeft = ((gz + 1)*VERTEX_COUNT) + gx;
			int bottomRight = bottomLeft + 1;
			indices[pointer++] = topLeft;
			indices[pointer++] = bottomLeft;
			indices[pointer++] = topRight;
			indices[pointer++] = topRight;
			indices[pointer++] = bottomLeft;
			indices[pointer++] = bottomRight;
		}
	}
	return loader.loadToVAO(vertices, textures, normals, indices);
}

GLfloat Terrain::getX()
{
	return m_x;
}

GLfloat Terrain::getZ()
{
	return m_z;
}

RawModel Terrain::getRawModel()
{
	return m_model;
}

ModelTexture Terrain::getTexture()
{
	return m_texture;
}
