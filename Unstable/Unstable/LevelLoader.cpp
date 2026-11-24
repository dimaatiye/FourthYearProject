#include "LevelLoader.h"
#include <iostream>
#include <yaml-cpp/yaml.h>



void operator >> (const YAML::Node& t_platformNode, PlatformData& t_platform)
{
    t_platform.m_active = true;
    t_platform.m_triggered = false;
    t_platform.m_playerStandingOnPlatform = false;

    t_platform.m_type = t_platformNode["type"].as<std::string>();

    t_platform.m_position.x = t_platformNode["position"]["x"].as<float>();

    t_platform.m_position.y = t_platformNode["position"]["y"].as<float>();

    t_platform.m_size.x = t_platformNode["size"]["x"].as<float>();

    t_platform.m_size.y = t_platformNode["size"]["y"].as<float>();

    if (t_platform.m_type == "moving")
    {
        t_platform.m_startPosition = t_platform.m_position;

        t_platform.m_endPosition = Vector2{
            t_platformNode["endPosition"]["x"].as<float>(),
            t_platformNode["endPosition"]["y"].as<float>()
        };

        t_platform.m_speed = t_platformNode["speed"].as<float>();
        t_platform.m_direction = 1;
    }

}


void operator >> (const YAML::Node& t_playerNode, PlayerData& t_player)
{
    t_player.m_position.x = t_playerNode["position"]["x"].as<float>();

    t_player.m_position.y = t_playerNode["position"]["y"].as<float>();
}

void operator >> (const YAML::Node& t_starNode, StarData& t_star)
{
	t_star.m_position.x = t_starNode["position"]["x"].as<float>();

	t_star.m_position.y = t_starNode["position"]["y"].as<float>();

	t_star.outerRadius = t_starNode["outerRadius"].as<float>();

	t_star.innerRadius = t_starNode["innerRadius"].as<float>();

    t_star.m_active = true;
}
void operator >> (const YAML::Node& t_enemyNode, EnemyData& t_enemy)
{
    t_enemy.m_position.x = t_enemyNode["position"]["x"].as<float>();
    t_enemy.m_position.y = t_enemyNode["position"]["y"].as<float>();

    t_enemy.m_startPosition = t_enemy.m_position;

    t_enemy.m_endPosition.x = t_enemyNode["endPosition"]["x"].as<float>();
    t_enemy.m_endPosition.y = t_enemyNode["endPosition"]["y"].as<float>();

    t_enemy.m_radius = t_enemyNode["radius"].as<float>();
    t_enemy.m_speed = t_enemyNode["speed"].as<float>();

    t_enemy.m_direction = 1;
}
void operator >> (const YAML::Node& t_followerNode, FollowerEnemyData& t_follower)
{
    t_follower.m_position.x = t_followerNode["position"]["x"].as<float>();
    t_follower.m_position.y = t_followerNode["position"]["y"].as<float>();
    t_follower.m_speed = t_followerNode["speed"].as<float>();
    t_follower.m_size = t_followerNode["size"].as<float>(40.0f);              
    t_follower.m_sightRange = t_followerNode["sightRange"].as<float>(400.0f); 
}
void operator >> (const YAML::Node& t_levelNode, LevelData& t_level)
{
    t_levelNode["player"] >> t_level.m_player;
    if (t_levelNode["gravityDirection"])
    {
        t_level.m_gravityDirection = t_levelNode["gravityDirection"].as<float>();
    }
    else
    {
        t_level.m_gravityDirection = 1.0f;
    }

    const YAML::Node& platformsNode = t_levelNode["platforms"];

    t_level.m_platforms.clear();

    for (unsigned int i = 0; i < platformsNode.size(); ++i)
    {
        PlatformData platform;
        platformsNode[i] >> platform;
        t_level.m_platforms.push_back(platform);
    }
	t_level.m_star.m_active = false; 
    t_levelNode["star"] >> t_level.m_star;

    t_level.m_enemies.clear();
    if (t_levelNode["enemies"])
    {
        const YAML::Node& enemiesNode = t_levelNode["enemies"]; //get the list of enemies from the yaml file

        for (unsigned int i = 0; i < enemiesNode.size(); ++i)
        {
            EnemyData enemy;
            enemiesNode[i] >> enemy;
            t_level.m_enemies.push_back(enemy);
        }
    }
    t_level.m_followers.clear();
    if (t_levelNode["followers"])
    {
        const YAML::Node& followersNode = t_levelNode["followers"];

        for (unsigned int i = 0; i < followersNode.size(); ++i)
        {
            FollowerEnemyData follower;
            followersNode[i] >> follower;
            t_level.m_followers.push_back(follower);
        }
    }
}

void LevelLoader::load(int t_levelNum, LevelData& t_level)
{
    std::string filename ="levels/level" + std::to_string(t_levelNum) + ".yaml";


     YAML::Node baseNode = YAML::LoadFile(filename);

     baseNode >> t_level;
    

}

void TestYAML()
{
    YAML::Node level = YAML::LoadFile("levels/level1.yaml");

}
