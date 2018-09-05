#pragma once

class Shader
{
public:
	Shader(const std::string& vertexFile, const std::string& fragmentFile);

	void start();

	void stop();

	void cleanUp();

protected:
	virtual void bindAttributes() = 0;

	virtual void getAllUniformLocations() = 0;

	void bindAttribute(GLuint attribute, std::string variableName);

	GLuint getUniformLocation(const std::string& uniformName);

	void loadFloat(GLuint location, GLfloat value);

	void loadVector(GLuint location, glm::vec3 vector);

	void loadBool(GLuint location, GLboolean value);

	void loadMatrix(GLuint location, glm::mat4 matrix);

private:
	static GLuint loadShader(const std::string& file, GLuint type);

private:
	GLuint			m_shader_id;
	GLuint			m_vertex_id;
	GLuint			m_fragment_id;
};

