#pragma once
#include "raylib.h"

enum HUDChoice
{
    HUD_NONE,
    HUD_BACK,
    HUD_REPLAY
};

class HUD
{
private:
    Rectangle m_backButton;
    Rectangle m_replayButton;

public:
    HUD();

    void Draw();
    HUDChoice Update();
};