#include "Information.h"

Information::Information()
{
	m_backButton = { x, y, w , h };

}
void Information::Draw()
{
	DrawText("This is a platformer game. Use arrow keys to move and space to jump.", 100, 290, 20, WHITE);
	DrawText("Press ESC to return to the menu.", 100, 350, 20, WHITE);
	DrawText("Press C to change Bob's color", 100, 350, 20, WHITE);

	DrawRectangleRec(m_backButton, PINK);
	DrawText("BACK", x+10, y+10, 20, BLACK);
}

bool Information::Update()
{
	Vector2 mousePosition = GetMousePosition();
	if (CheckCollisionPointRec(mousePosition, m_backButton))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			return true;
		}
	}
	return false;
}