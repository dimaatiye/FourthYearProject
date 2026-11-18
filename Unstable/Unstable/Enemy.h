#pragma once
#include "raylib.h"

class Enemy
{
private:
    Vector2 m_position;
    float m_radius;

public:
    Enemy();

    void Draw();
};
