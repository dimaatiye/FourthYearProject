#include "raylib.h"
#include "Player.h"
#include "main.h"
#include <yaml-cpp/yaml.h>
#include "LevelLoader.h"
#include <iostream>
#include "Collision.h"


int main() {

	InitWindow(1100, 800, "Unstable");
	SetTargetFPS(60);
	Player player;
	LevelData level;
	Collision collision;
	
	LevelLoader::load(1, level);
	player.SetPosition(level.m_player.m_position);

	std::cout << "Player X: "
		<< level.m_player.m_position.x << std::endl;
	std::cout << "Player Y: "
		<< level.m_player.m_position.y << std::endl;

	std::cout << "Number of platforms: "
		<< level.m_platforms.size() << std::endl;
	TestYAML();

	while(!WindowShouldClose()) {
		player.Update();
		collision.CheckPlatforms(player, level);

		BeginDrawing();
		ClearBackground(BLACK);

		player.Draw();
		for (const PlatformData& platform : level.m_platforms)
		{
			DrawRectangle(
				(int)platform.m_position.x,
				(int)platform.m_position.y,
				(int)platform.m_size.x,
				(int)platform.m_size.y,
				WHITE
			);
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}