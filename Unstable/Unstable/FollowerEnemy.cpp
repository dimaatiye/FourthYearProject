#include "FollowerEnemy.h"

FollowerEnemy::FollowerEnemy(FollowerEnemyData t_data)
{
	m_data = t_data;
}

void FollowerEnemy::Update(Vector2 t_playerPosition)
{
	float playerTop = t_playerPosition.y - 115;
	float playerBottom = t_playerPosition.y - 30;
    bool sameRow = playerTop < m_data.m_position.y + SIZE  && playerBottom > m_data.m_position.y;

    if (sameRow)
    {
        if (t_playerPosition.x > m_data.m_position.x)
        {
            m_data.m_position.x += m_data.m_speed;
        }
        else
        {
            m_data.m_position.x -= m_data.m_speed;
        }
    }

}
void FollowerEnemy::Draw()
{
	DrawRectangleRec(GetRect(), RED);

}

Rectangle FollowerEnemy::GetRect()
{
	return { m_data.m_position.x, m_data.m_position.y, SIZE, SIZE };
}
