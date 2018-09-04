#pragma once

class RawModel;

class Renderer
{
public:
	Renderer();
	
	void prepare();

	void render(RawModel model);
};

