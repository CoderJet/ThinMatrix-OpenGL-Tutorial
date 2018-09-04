#pragma once

class Shader
{
public:
	Shader(std::string vertexFile, std::string fragmentFile);

	void start();

	void stop();

	void cleanUp();

protected:
	virtual void bindAttributes() = 0;

	void bindAttribute(GLuint attribute, std::string variableName);

private:
	static GLuint loadShader(std::string file, GLuint type);

private:
	GLuint			m_shader_id;
	GLuint			m_vertex_id;
	GLuint			m_fragment_id;
};

