#pragma once

#include "Shader.h"

class StaticShader : public Shader
{
public:
	StaticShader();

	virtual void bindAttributes() override;
};

