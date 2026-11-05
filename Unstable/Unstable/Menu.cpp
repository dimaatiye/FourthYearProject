#include "Menu.h"
Menu::Menu()
{
	m_startButton = { 360, 350, 320, 60 };
	m_quitButton = { 360, 420, 320, 60 };
	m_infoButton = { 360, 490, 450, 60 };
}
void Menu::Draw()
{
	DrawText("Unstable", 320, 200, 90, WHITE);
	DrawRectangleRec(m_startButton, PINK);
	DrawRectangleRec(m_quitButton, YELLOW);
	DrawRectangleRec(m_infoButton, GREEN);
	DrawText("START", 410, 350, 60, BLACK);
	DrawText("QUIT", 450, 430, 60, BLACK);
	DrawText("INFORMATION", 370, 500, 60, BLACK);

}

MenuChoice Menu::Update()
{
	Vector2 mousePosition = GetMousePosition();

	if(CheckCollisionPointRec(mousePosition, m_startButton))
	{
		if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return START;
		}
	}
	if (CheckCollisionPointRec(mousePosition, m_quitButton))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return QUIT;
		}
	}
	if (CheckCollisionPointRec(mousePosition, m_infoButton))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return INFO;
		}
	}

	return NONE;

}