#include "Collision.h"

void Collision::CheckPlatforms(Player& t_player, LevelData& t_level)
{
    Vector2 playerPosition = t_player.GetPosition();

    Rectangle playerRect = { playerPosition.x - 7, playerPosition.y - 115, 32, 85 };
   
    for (const PlatformData& platform : t_level.m_platforms)
    {
        Rectangle platformRect = { platform.m_position.x, platform.m_position.y, platform.m_size.x, platform.m_size.y };
    }

}
