#pragma once
enum GameStatus
{
    ALIVE,
    DEAD,
    WIN
};
class GameState
{
private:
    GameStatus m_status;

public:
    GameState();

    void SetStatus(GameStatus t_status);
    GameStatus GetStatus() const;
};

