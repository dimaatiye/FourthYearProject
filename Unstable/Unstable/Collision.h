#pragma once
#include "Player.h"
#include "LevelLoader.h"
class Collision
{
private:

public:
	void CheckPlatforms(Player& t_player, LevelData& t_level);
	void CheckDisappearingPlatform(Player& t_player, LevelData& t_level);
};

