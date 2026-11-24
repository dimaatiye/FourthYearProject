#include "Collision.h"
#include "raymath.h"
void Collision::CheckPlatforms(Player& t_player, LevelData& t_level)
{
    Vector2 playerPosition = t_player.GetPosition();

    Rectangle playerRect = { playerPosition.x - 7, playerPosition.y - 115, playerCollisionWidth, playerCollisionHeight };
   
    for (PlatformData& platform : t_level.m_platforms)
    {
        platform.m_playerStandingOnPlatform = false;
    }

    for (PlatformData& platform : t_level.m_platforms)
    {
            if (platform.m_active)
            {
                Rectangle platformRect = { platform.m_position.x, platform.m_position.y, platform.m_size.x, platform.m_size.y };
                if (CheckCollisionRecs(playerRect, platformRect))
                {
                    Vector2 velocity = t_player.GetVelocity();

                    if (velocity.y > 0)//if the player is faliing.
                    {
                        float playerFeet = playerPosition.y - feetOffset;
                        float platformTop = platform.m_position.y;

                        if (playerFeet >= platformTop) {
                            t_player.SetPosition({ playerPosition.x, platformTop + feetOffset });
                            t_player.SetVelocity({ 0, 0 });
                            platform.m_playerStandingOnPlatform = true;

                        }
                    }
                    else if (velocity.y < 0 && t_player.GetGravityDirection() < 0)
                    {

                        float playerHead = playerPosition.y - 115;
                        float platformBottom = platform.m_position.y + platform.m_size.y;


                        if ( playerHead <= platformBottom)
                        {
                            t_player.SetPosition({ playerPosition.x, platformBottom + 115 });
                            t_player.SetVelocity({ 0, 0 });
                            platform.m_playerStandingOnPlatform = true;
                        }
                    }
                }
            }

        
    
    }
  
}


bool Collision::CheckStar(Player& t_player, LevelData& t_level)
{
    if (!t_level.m_star.m_active)
    {
        return false;
    }
    Vector2 playerPosition = t_player.GetPosition();
    Rectangle playerRect = { playerPosition.x - 7, playerPosition.y - 115,playerCollisionWidth, playerCollisionHeight};

    if (CheckCollisionCircleRec( t_level.m_star.m_position, t_level.m_star.outerRadius, playerRect))
    {
        t_level.m_star.m_active = false;
        return true;
    }

    return false;
}
