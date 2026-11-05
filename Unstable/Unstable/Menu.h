#pragma once
#include "raylib.h"
enum MenuChoice
{
	NONE,
	START,
	QUIT,
	INFO
};
class Menu
{
private :

	Rectangle m_startButton;
	Rectangle m_quitButton;
	Rectangle m_infoButton;
	float x = 360;
	float y = 350;
	float w = 320;
	float h = 60;
	float textSize = 60;

public:
	Menu();
	void Draw();
	MenuChoice Update();

};


