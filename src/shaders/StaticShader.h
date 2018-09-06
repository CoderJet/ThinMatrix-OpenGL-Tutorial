#pragma once
// Local includes.
#include "Shader.h"

class Camera;
class Light;

class StaticShader : public Shader
{
public:
	StaticShader();

	virtual void bindAttributes() override;

	virtual void getAllUniformLocations() override;

	void loadTransformationMatrix(glm::mat4 matrix);

	void loadProjectionMatrix(glm::mat4 projection);

	void loadViewMatrix(Camera& camera);

	void loadLight(Light& light);

	void loadShineVariables(float damper, float reflectivity);

private:
	GLuint			m_transformation_matrix_id;
	GLuint			m_projection_matrix_id;
	GLuint			m_view_matrix_id;
	GLuint			m_light_position_id;
	GLuint			m_light_colour_id;
	GLuint			m_shine_damper_id;
	GLuint			m_reflectivity_id;
};

