#pragma once
#include "raylib.h"

enum HUDChoice
{
    HUD_NONE,
    HUD_BACK,
    HUD_REPLAY,
	HUD_NEXT_LEVEL
};

class HUD
{
private:
    Rectangle m_backButton;
    Rectangle m_replayButton;
	Rectangle m_nextLevelButton;

public:
    HUD();

    void Draw(bool t_levelComplete);
    HUDChoice Update(bool t_levelComplete);
};