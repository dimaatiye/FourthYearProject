#include "Enemy.h"
Enemy::Enemy(EnemyData t_data)
{
    m_data = t_data;
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