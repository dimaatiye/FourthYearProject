#include "PlatformManager.h"
#include "raymath.h"
void PlatformManager::Update(Player& t_player, LevelData& t_level)
{
	UpdateDisappearingPlatforms(t_player, t_level);

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
