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
