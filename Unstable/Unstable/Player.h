#pragma once
#include "raylib.h"
#include <iostream>
enum class PlayerState
{
	Idle,
	Jumping,
	WalkLeft,
	WalkRight
};
class Player
{
public:
	Player();
	void Update();
	void Draw();
	PlayerState state = PlayerState::Idle;
	void SetPosition(Vector2 t_position);
	Vector2 GetPosition();
	Vector2 GetVelocity();
	void SetVelocity(Vector2 t_velocity);

private:
	Vector2 position = { 400,500 };
	Vector2 velocity = { 0,0 };

	float speed = 10.0f;
	float jumpForce = -40.0f;
	float gravity = 4;

	Color color[5] = { WHITE, GREEN, BLUE, PINK, PURPLE };
	int colorIndex = 0;
	Color playerColor = color[colorIndex];
	bool colorSelected = false;
	Color drawColor;
	bool DisableEnter = false;

	void DrawBody();
	void DrawIdle();
	void DrawJumping();
	void DrawWalkLeft();
	void DrawWalkRight();
	void DrawWalking();

	int frame = 0;
};

