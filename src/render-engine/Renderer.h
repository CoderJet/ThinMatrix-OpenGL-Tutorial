#pragma once

class Entity;
class StaticShader;

class Renderer
{
public:
	Renderer(StaticShader& shader);
	
	void prepare();

	void render(Entity& entity, StaticShader& shader);

private:
	void createProjectionMatrix();

private:
	const GLfloat		FOV{ 70.0f };
	const GLfloat		NEAR_PLANE{ 0.1f };
	const GLfloat		FAR_PLANE{ 1000.0f };

	glm::mat4			m_projection_matrix;
};

