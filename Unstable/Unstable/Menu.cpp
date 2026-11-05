#include "Menu.h"
Menu::Menu()
{
	m_startButton = { 400, 300, 200, 50 };
}
void Menu::Draw()
{
	DrawText("Unstable", 400, 200, 50, WHITE);
	DrawRectangleRec(m_startButton, PINK);
	DrawText("START", 400, 300, 20, WHITE);
}

bool Menu::Update()
{
	Vector2 mousePosition = GetMousePosition();

	if(CheckCollisionPointRec(mousePosition, m_startButton))
	{
		if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return true;
		}
	}


}