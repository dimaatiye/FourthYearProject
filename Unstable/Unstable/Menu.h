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

public:
	Menu();
	void Draw();
	MenuChoice Update();

};


