#pragma once
#include "Player.h"
#include "LevelLoader.h"
#include "FollowerEnemy.h"

class Collision
{
private:
	float playerCollisionWidth = 32;
	float playerCollisionHeight = 85;
	//float playerFeet = 30;
	const float feetOffset = 30.0f;
public:
	void CheckPlatforms(Player& t_player, LevelData& t_level);
	bool CheckStar(Player& t_player, LevelData& t_level);
	bool CheckFollower(Player& t_player, FollowerEnemy& t_follower);
};

