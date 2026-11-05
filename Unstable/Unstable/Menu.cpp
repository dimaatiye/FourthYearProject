#include "Menu.h"
Menu::Menu()
{

	m_startButton = { x, y, w, h };
	m_quitButton = { x, y + 70, w, h };
	m_infoButton = { x, y + 140, w +130, h };
}
void Menu::Draw()
{
	DrawText("Unstable", x - 40, y - 150, textSize + 30, WHITE);
	DrawRectangleRec(m_startButton, PINK);
	DrawRectangleRec(m_quitButton, YELLOW);
	DrawRectangleRec(m_infoButton, GREEN);
	DrawText("START", x +50, y, textSize, BLACK);
	DrawText("QUIT", x + 90, y +80, textSize, BLACK);
	DrawText("INFORMATION", x+10, y+150, textSize, BLACK);

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