#pragma once
#include "raylib.h"
class Menu
{
private :

	Rectangle m_startButton;

public:
	Menu();
	void Draw();
	bool Update();
};

