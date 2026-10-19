#include "raylib.h"
#include "Player.h"
#include "main.h"
#include <yaml-cpp/yaml.h>
int main() {

	InitWindow(1100, 800, "Unstable");
	SetTargetFPS(60);
	Player player;
	
	while(!WindowShouldClose()) {
		player.Update();
		BeginDrawing();
		ClearBackground(BLACK);

		player.Draw();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}