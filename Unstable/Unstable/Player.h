#pragma once
#include "raylib.h"
class Player
{
public:
	Player();
	void Update();
	void Draw();

private:
	Vector2 position = { 400,500 };
	Vector2 velocity = { 0,0 };

	float speed = 5.0f;
	float jumpForce = -10.0f;
	float gravity = 0.5;

};

