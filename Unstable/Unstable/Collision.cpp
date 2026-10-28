#include "Collision.h"

void Collision::CheckPlatforms(Player& t_player, LevelData& t_level)
{
    Vector2 playerPosition = t_player.GetPosition();

    Rectangle playerRect = { playerPosition.x - 7, playerPosition.y - 115, 32, 85 };
   
    for (const PlatformData& platform : t_level.m_platforms)
    {
        Rectangle platformRect = { platform.m_position.x, platform.m_position.y, platform.m_size.x, platform.m_size.y };
        if (CheckCollisionRecs(playerRect, platformRect))
        {
            Vector2 velocity = t_player.GetVelocity();

            if (velocity.y > 0)
            {
                float playerFeet = playerPosition.y - 30;
                float platformTop = platform.m_position.y;

                float previousFeet = playerFeet - velocity.y;

                if (previousFeet <= platformTop && playerFeet >= platformTop){
                    t_player.SetPosition({playerPosition.x, platformTop + 30 });
                    t_player.SetVelocity({ 0, 0 });
                }
            }
        }
    
    }
  
}
