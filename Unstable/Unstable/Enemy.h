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
    Enemy(EnemyData t_data);
    bool CheckCollision(Vector2 t_playerPosition);
    void Update();
    void Draw();
};
