#pragma once
#include "raylib.h"
class Information
{
private:


	float x = 10;
	float y = 10;
	float w = 100;
	float h = 40;
	float textSize = 60;
	Rectangle m_backButton;
public:
	Information();
	void Draw();
	bool Update();
};

