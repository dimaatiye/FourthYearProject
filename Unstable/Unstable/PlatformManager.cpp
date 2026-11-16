#include "PlatformManager.h"
#include "raymath.h"
void PlatformManager::Update(Player& t_player, LevelData& t_level)
{
	UpdateDisappearingPlatforms(t_player, t_level);
	UpdateMovingPlatforms(t_player, t_level);

}

void PlatformManager::UpdateDisappearingPlatforms(Player& t_player, LevelData& t_level)
{
    Vector2 playerPosition = t_player.GetPosition();

    for (PlatformData& platform : t_level.m_platforms)
    {
        if (platform.m_type == "disappearing" && platform.m_active)
        {
            float distance = Vector2Distance(playerPosition, platform.m_position);

            if (distance < 70)
            {
                platform.m_triggered = true;
                platform.m_active = false;
            }
        }
    }
}
void PlatformManager::UpdateMovingPlatforms(Player& t_player, LevelData& t_level)
{
    for (PlatformData& platform : t_level.m_platforms)
    {
        if (platform.m_type == "moving" && platform.m_active)
        {
           // platform.m_position.x += platform.m_speed * platform.m_direction;
            float movement = platform.m_speed * platform.m_direction;//lets the player stick to the moving platform

            platform.m_position.x += movement;
            if (platform.m_position.x >= platform.m_endPosition.x)
            {
                platform.m_direction = -1;
            }
            // Move the player if standing on this platform
            if (platform.m_playerStandingOnPlatform)
            {
                Vector2 playerPosition = t_player.GetPosition();

                playerPosition.x += movement;

                t_player.SetPosition(playerPosition);
            }

            if (platform.m_position.x <= platform.m_startPosition.x)
            {
                platform.m_direction = 1;
            }
        }
    }
}