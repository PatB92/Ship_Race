#pragma once
#include "Component.h"
#include "engine.h"

class FontApp
	:Component
{
public:
	FontApp();
	~FontApp();

	void OnLostDevice();
	void OnResetDevice();
	void Update();
	void Draw();

private:

	ID3DXFont* mFont;

	int score;

};

