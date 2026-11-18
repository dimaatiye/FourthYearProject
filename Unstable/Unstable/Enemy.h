#pragma once
#include "raylib.h"
#include "LevelLoader.h"

class Enemy
{
private:
    Vector2 m_position;
    float m_radius;
    EnemyData m_data;

public:
    Enemy(EnemyData m_data);
    void Update();
    void Draw();
};
