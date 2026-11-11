#include "GameState.h"
#include "raylib.h"
GameState::GameState()
{
	m_status = ALIVE;
}

void GameState::SetStatus(GameStatus t_status)
{
	m_status = t_status;

}

GameStatus GameState::GetStatus() const
{
	return m_status;
}

void GameState::Dead()
{
	DrawRectangle(0, 0, 110, 800, BLACK);
	DrawText("GAME OVER!", 400, 350, 40, RED);
	DrawText("You have died!", 440, 410, 20, WHITE);
}

void GameState::Win()
{
	DrawRectangle(0, 0, 1100, 800, BLACK);
	DrawText("YOU WIN!", 400, 350, 40, GREEN);

}
