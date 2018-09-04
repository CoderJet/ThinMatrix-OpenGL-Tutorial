#pragma once

class TexturedModel;

class Renderer
{
public:
	Renderer();
	
	void prepare();

	void render(TexturedModel texturedModel);
};

