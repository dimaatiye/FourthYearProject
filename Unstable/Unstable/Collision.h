#pragma once
#include "Player.h"
#include "LevelLoader.h"
class Collision
{
private:
	float playerCollisionWidth = 32;
	float playerCollisionHeight = 85;
	float playerFeet = 30;
public:
	void CheckPlatforms(Player& t_player, LevelData& t_level);
	void CheckDisappearingPlatform(Player& t_player, LevelData& t_level);
};

