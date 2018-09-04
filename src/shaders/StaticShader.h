#pragma once

#include "Shader.h"

class StaticShader : public Shader
{
public:
	StaticShader();

	virtual void bindAttributes() override;

	virtual void getAllUniformLocations() override;

	void loadTransformationMatrix(glm::mat4 matrix);

private:
	GLuint			m_transformation_matrix_id;
};

