#include "raylib.h"
#include "Player.h"
#include "main.h"
#include <yaml-cpp/yaml.h>
#include "LevelLoader.h"
#include <iostream>
#include "Collision.h"
#include "Menu.h"
#include "Information.h"
#include "HUD.h"
#include "GameState.h"
#include "Star.h"

int main() {

	InitWindow(1100, 800, "Unstable");
	SetTargetFPS(60);
	Player player;
	LevelData level;
	Collision collision;
	Information information;
	HUD hud;
	Menu menu;
	LevelLoader::load(1, level);
	GameState gameState;
	Star star;
	player.SetPosition(level.m_player.m_position);
	bool started = false;
	bool ended = false;
	bool infoScreen = false;
	std::cout << "Player X: "<< level.m_player.m_position.x << std::endl;
	std::cout << "Player Y: "<< level.m_player.m_position.y << std::endl;
	std::cout << "Number of platforms: "<< level.m_platforms.size() << std::endl;
	TestYAML();

	while(!WindowShouldClose() && !ended) {

		BeginDrawing();
		ClearBackground(BLACK);
		if (!started)
		{
			if (infoScreen)
			{
				information.Draw();

				if (information.Update())
				{
					infoScreen = false;
				}
			}
			else
			{
				menu.Draw();

				MenuChoice choice = menu.Update();

				if (choice == START)
				{
					started = true;
					gameState.SetStatus(ALIVE);

				}
				else if (choice == QUIT)
				{
					ended = true;
				}
				else if (choice == INFO)
				{
					infoScreen = true;
				}
			}
		}
		else
		{
			if (gameState.GetStatus() == ALIVE)
			{
				//star.DrawStar({ 550, 400 }, 40, 16, 0, YELLOW);
				player.Update();
				if (player.GetPosition().y >= 825)
				{

					gameState.SetStatus(DEAD);
				}
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
				if (level.m_star.m_active)
				{
					star.DrawStar(level.m_star.m_position, level.m_star.outerRadius, level.m_star.innerRadius, 0, YELLOW);
				}
				
			}
			else if (gameState.GetStatus() == DEAD)
			{
				player.Draw();  // Draw the player in their final position
				gameState.Dead();
			}
			else if (gameState.GetStatus() == WIN)
			{
				gameState.Win();
			}
			hud.Draw();

			HUDChoice hudChoice = hud.Update();

			if (hudChoice == HUD_BACK)
			{
				gameState.SetStatus(ALIVE);
				LevelLoader::load(1, level);
				player.SetPosition(level.m_player.m_position);
				player.SetVelocity({ 0, 0 });
				started = false;
			}
			else if (hudChoice == HUD_REPLAY)
			{
				gameState.SetStatus(ALIVE);
				LevelLoader::load(1, level);
				player.SetPosition(level.m_player.m_position);
				player.SetVelocity({ 0, 0 });
			}
		}
			EndDrawing();
		
	}

	CloseWindow();
	return 0;
}