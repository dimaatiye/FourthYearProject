#include "Player.h"

Player::Player()
{

}

void Player::Update()
{
	if(IsKeyPressed(KEY_C)) {
		colorIndex++;
		if (colorIndex >= 5) {
			colorIndex = 0;
		}
	}
}

void Player::Draw()
{
	DrawRectangle(position.x, position.y, 50, 50, color[colorIndex]);
}
