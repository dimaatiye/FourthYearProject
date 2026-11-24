#pragma once
#include "raylib.h"
#include "LevelLoader.h"   

class FollowerEnemy
{
public:
    FollowerEnemy(FollowerEnemyData t_data);

    void Update(Vector2 t_playerPosition);
    void Draw();
    Rectangle GetRect();

private:
    FollowerEnemyData m_data;
    const float SIZE = 20.0f;   

};