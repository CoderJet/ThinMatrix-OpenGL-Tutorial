#include "stdafx.h"
#include "StaticShader.h"

StaticShader::StaticShader()
	: Shader("./src/shaders/Basic.vert", "./src/shaders/Basic.frag")
{
}

void StaticShader::bindAttributes()
{
	this->bindAttribute(0, "position");
	this->bindAttribute(1, "textureCoords");
}
