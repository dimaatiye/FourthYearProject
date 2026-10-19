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
};

/// <summary>
/// @brief A struct to represent player data in the level.
/// </summary>
struct PlayerData
{
	Vector2 m_position;
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
};

/// <summary>
/// @brief A class to manage level loading.
/// 
/// This class loads and parses level data using YAML.
/// </summary>
class LevelLoader
{
	/// <summary>
/// @brief No-op default constructor.
/// </summary>
	LevelLoader() = default;
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
};

