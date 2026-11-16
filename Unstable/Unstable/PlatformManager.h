#pragma once
#include "LevelLoader.h"
#include "Player.h"
#include "raylib.h"
class PlatformManager
{
public:
	void Update(Player& t_player, LevelData& t_level);

private:
	void UpdateDisappearingPlatforms(Player& t_player, LevelData& t_level);
};

