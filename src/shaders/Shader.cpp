#include "stdafx.h"

#include "Shader.h"

Shader::Shader(std::string vertexFile, std::string fragmentFile)
{
	m_vertex_id = loadShader(vertexFile, GL_VERTEX_SHADER);
	m_fragment_id = loadShader(fragmentFile, GL_FRAGMENT_SHADER);

	m_shader_id = glCreateProgram();
	glAttachShader(m_shader_id, m_vertex_id);
	glAttachShader(m_shader_id, m_fragment_id);
	glLinkProgram(m_shader_id);
	glValidateProgram(m_shader_id);
}

void Shader::start()
{
	glUseProgram(m_shader_id);
}

void Shader::stop()
{
	glUseProgram(0);
}

void Shader::cleanUp()
{
	stop();
	glDetachShader(m_shader_id, m_vertex_id);
	glDetachShader(m_shader_id, m_fragment_id);
	glDeleteShader(m_vertex_id);
	glDeleteShader(m_fragment_id);
	glDeleteProgram(m_shader_id);
}

void Shader::bindAttribute(GLuint attribute, std::string variableName)
{
	glBindAttribLocation(m_shader_id, attribute, variableName.c_str());
}

GLuint Shader::getUniformLocation(std::string uniformName)
{
	return glGetUniformLocation(m_shader_id, uniformName.c_str());
}

void Shader::loadFloat(GLuint location, GLfloat value)
{
	glUniform1f(location, value);
}

void Shader::loadVector(GLuint location, glm::vec3 vector)
{
	glUniform3f(location, vector.x, vector.y, vector.z);
}

void Shader::loadBool(GLuint location, GLboolean value)
{
	glUniform1f(location, value);
}

void Shader::loadMatrix(GLuint location, glm::mat4 matrix)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}

GLuint Shader::loadShader(std::string file, GLuint type)
{
	std::string shaderCode;
	std::ifstream shaderFile;
	// ensure ifstream objects can throw exceptions:
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		shaderFile.open(file.c_str());
		std::stringstream shaderStream;
		// read file's buffer contents into streams
		shaderStream << shaderFile.rdbuf();
		// close file handlers
		shaderFile.close();
		// convert stream into string
		shaderCode = shaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	const char* source = shaderCode.c_str();
	
	GLuint shaderID(glCreateShader(type));
	glShaderSource(shaderID, 1, &source, NULL);
	glCompileShader(shaderID);

	GLint success;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char info[1024];

		glGetShaderInfoLog(shaderID, 1024, NULL, info);
		std::cout << info << std::endl;
		std::cout << "Could not compile shader." << std::endl;
	}
	return shaderID;
}
