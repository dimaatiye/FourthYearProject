#include "HUD.h"

HUD::HUD()
{
    m_backButton = { 20, 20, 100, 40 };
    m_replayButton = { 965, 20, 120, 40 };
    m_nextLevelButton = { 390, 430, 320, 60 };
}

void HUD::Draw(bool t_levelComplete)
{
    DrawRectangleRec(m_backButton, PINK);
    DrawText("BACK", 45, 30, 20, BLACK);

    DrawRectangleRec(m_replayButton, YELLOW);
    DrawText("REPLAY", 985, 30, 20, BLACK);

    if (t_levelComplete)
    {
        DrawRectangleRec(m_nextLevelButton, GREEN);
        DrawText("NEXT LEVEL", 465, 448, 25, BLACK);
    }
}

HUDChoice HUD::Update(bool t_levelComplete)
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
        if (t_levelComplete)
        {
            if (CheckCollisionPointRec(mousePosition, m_nextLevelButton))
            {
                return HUD_NEXT_LEVEL;
            }
        }
    }


    return HUD_NONE;
}