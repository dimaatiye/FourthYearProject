#include "Enemy.h"
Enemy::Enemy(EnemyData t_data)
{
    m_data = t_data;
}
bool Enemy::CheckCollision(Vector2 t_playerPosition)
{
    Rectangle playerRectangle =
    {t_playerPosition.x - 7, t_playerPosition.y - 115, 32, 85};

    return CheckCollisionCircleRec( m_data.m_position,m_data.m_radius,playerRectangle);
}
void Enemy::Update()
{
    m_data.m_position.x += m_data.m_speed * m_data.m_direction;//move the enemy

    if (m_data.m_position.x >= m_data.m_endPosition.x)
    {
        m_data.m_direction = -1;
    }

    if (m_data.m_position.x <= m_data.m_startPosition.x)
    {
        m_data.m_direction = 1;
    }
}
void Enemy::Draw()
{
    DrawCircle( static_cast<int>(m_data.m_position.x), static_cast<int>(m_data.m_position.y), m_data.m_radius, RED );
}