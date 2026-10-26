#include "LevelLoader.h"
#include <iostream>
#include <yaml-cpp/yaml.h>


void operator >> (const YAML::Node& t_platformNode, PlatformData& t_platform)
{
    t_platform.m_type = t_platformNode["type"].as<std::string>();

    t_platform.m_position.x = t_platformNode["position"]["x"].as<float>();

    t_platform.m_position.y = t_platformNode["position"]["y"].as<float>();

    t_platform.m_size.x = t_platformNode["size"]["x"].as<float>();

    t_platform.m_size.y = t_platformNode["size"]["y"].as<float>();

}


void operator >> (const YAML::Node& t_playerNode, PlayerData& t_player)
{
    t_player.m_position.x = t_playerNode["position"]["x"].as<float>();

    t_player.m_position.y = t_playerNode["position"]["y"].as<float>();
}


void operator >> (const YAML::Node& t_levelNode, LevelData& t_level)
{
    t_levelNode["player"] >> t_level.m_player;

    const YAML::Node& platformsNode = t_levelNode["platforms"];

    t_level.m_platforms.clear();

    for (unsigned int i = 0; i < platformsNode.size(); ++i)
    {
        PlatformData platform;
        platformsNode[i] >> platform;
        t_level.m_platforms.push_back(platform);
    }
}

void LevelLoader::load(int t_levelNum, LevelData& t_level)
{
    std::string filename ="levels/level" + std::to_string(t_levelNum) + ".yaml";

    try
    {
        YAML::Node baseNode = YAML::LoadFile(filename);
        std::cout << "Loading file: " << filename << std::endl;
        std::cout << "YAML contents:\n" << baseNode << std::endl;
        baseNode >> t_level;
    }
    catch (const YAML::Exception& e)
    {
        std::cout << "Could not load level: "
            << e.what() << std::endl;
    }
}

void TestYAML()
{
    YAML::Node level = YAML::LoadFile("levels/level1.yaml");

}
