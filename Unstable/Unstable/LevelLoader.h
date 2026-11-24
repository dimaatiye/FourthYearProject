#pragma once
#include "raylib.h"
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>


/// <summary>
/// @brief A struct to represent platform data in the level.
/// </summary>
struct PlatformData
{
	std::string m_type;
	Vector2 m_position;
	Vector2 m_size;

	bool m_active = true;
	bool m_triggered = false;
	Vector2 m_startPosition;
	Vector2 m_endPosition;
	float m_speed = 2.0f;
	int m_direction = 1;
	bool m_playerStandingOnPlatform = false;

};

/// <summary>
/// @brief A struct to represent player data in the level.
/// </summary>
struct PlayerData
{
	Vector2 m_position;
};
/// <summary>
/// @brief A struct to represent star data in the level. when the player touches the star, they win the level.
/// </summary>
struct StarData
{
	Vector2 m_position;
	float outerRadius;
	float innerRadius;
	bool m_active;
};
/// <summary>
/// @brief A struct representing all the enemies
/// 
/// enemy one is a circle with spikes
/// </summary>
struct EnemyData
{
	Vector2 m_position;
	Vector2 m_startPosition;
	Vector2 m_endPosition;
	float m_radius;
	float m_speed = 2.0f;
	int m_direction = 1;
};
/// <summary>
/// @brief A struct representing all the enemies
/// 
/// enemy two is what follows the player
/// </summary>
struct FollowerEnemyData
{
	Vector2 m_position;   
	float m_size;
	float m_speed;
};
/// <summary>
/// @brief A struct representing all the level data.
/// 
/// Platforms may be repeated and are therefore stored
/// in a container.
/// </summary>
struct LevelData
{
	PlayerData m_player;
	std::vector<PlatformData> m_platforms;
	StarData m_star;
	std::vector<EnemyData> m_enemies;
	float m_gravityDirection = 1.0f;
	std::vector<FollowerEnemyData> m_followers;

};
void TestYAML();
/// <summary>
/// @brief A class to manage level loading.
/// 
/// This class loads and parses level data using YAML.
/// </summary>
class LevelLoader
{
public:
 /// <summary>
 /// @brief Loads and parses a YAML level file.
 /// 
 /// The level file is identified by its number,
 /// for example "level1.yaml".
 /// The level information is stored in the supplied
 /// LevelData object.
 /// </summary>
 /// <param name="t_levelNr">The level number.</param>
 /// <param name="t_level">A reference to the LevelData object.</param>
    static void load(int t_levelNum, LevelData& t_level);

private:

};

