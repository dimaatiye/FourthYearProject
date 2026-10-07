#include "raylib.h"
#include "Player.h"
#include "main.h"
int main() {

	InitWindow(1100, 800, "Unstable");
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