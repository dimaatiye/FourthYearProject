#include "raylib.h"
#include "Player.h"
#include "main.h"
#include <yaml-cpp/yaml.h>
#include "LevelLoader.h"
#include <iostream>
#include "Collision.h"
#include "Menu.h"

int main() {

	InitWindow(1100, 800, "Unstable");
	SetTargetFPS(60);
	Player player;
	LevelData level;
	Collision collision;

	Menu menu;
	LevelLoader::load(1, level);
	player.SetPosition(level.m_player.m_position);
	bool started = false;
	bool ended = false;
	std::cout << "Player X: "
		<< level.m_player.m_position.x << std::endl;
	std::cout << "Player Y: "
		<< level.m_player.m_position.y << std::endl;

	std::cout << "Number of platforms: "
		<< level.m_platforms.size() << std::endl;
	TestYAML();

	while(!WindowShouldClose() && !ended) {

		BeginDrawing();
		ClearBackground(BLACK);
		if (!started)
		{
			menu.Draw();

			MenuChoice choice = menu.Update();

			if (choice == START)
			{
				started = true;
			}
			else if (choice == QUIT)
			{
				ended = true;
			}
		}
		else
		{
			player.Update();
			collision.CheckPlatforms(player, level);
			collision.CheckDisappearingPlatform(player, level);
			player.Draw();
			for (const PlatformData& platform : level.m_platforms)
			{
				if (platform.m_active)
				{
					DrawRectangle(
						(int)platform.m_position.x,
						(int)platform.m_position.y,
						(int)platform.m_size.x,
						(int)platform.m_size.y,
						WHITE
					);
				}
			}
		}
			EndDrawing();
		
	}

	CloseWindow();
	return 0;
}