#include "HUD.h"

HUD::HUD()
{
    m_backButton = { 20, 20, 100, 40 };
    m_replayButton = { 965, 20, 120, 40 };
}

void HUD::Draw()
{
    DrawRectangleRec(m_backButton, PINK);
    DrawText("BACK", 45, 30, 20, BLACK);

    DrawRectangleRec(m_replayButton, YELLOW);
    DrawText("REPLAY", 985, 30, 20, BLACK);
}

HUDChoice HUD::Update()
{
    Vector2 mousePosition = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        if (CheckCollisionPointRec(mousePosition, m_backButton))
        {
            return HUD_BACK;
        }

        if (CheckCollisionPointRec(mousePosition, m_replayButton))
        {
            return HUD_REPLAY;
        }
    }

    return HUD_NONE;
}