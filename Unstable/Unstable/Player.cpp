#include "Player.h"

Player::Player()
{

}

void Player::Update()
{
	if (colorSelected == false) {


		if (IsKeyPressed(KEY_C)) {
			colorIndex++;
			if (colorIndex >= 5) {
				colorIndex = 0;
			}
		}
		if (DisableEnter == false)
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				playerColor = color[colorIndex];
				colorSelected = true;
				std::cout << "Color selected: " << colorIndex << std::endl;
				DisableEnter = true;
			}
		}

	}
	else {
		//game starts after the player pressess enter
		velocity.y += gravity;
		position.y += velocity.y;

		if (position.y >= 750)
		{
			velocity.y = 0;
			position.y = 750;
		}
		if(position.x <= 0)
		{
			position.x = 0;
		}
		if(position.x >= 1050)
		{
			position.x = 1050;
		}
		if (IsKeyDown(KEY_LEFT))
		{
			position.x -= speed;
			std::cout << "player moving left " << std::endl;

		}
		if (IsKeyDown(KEY_RIGHT))
		{
			std::cout << "player moving right " << std::endl;
			position.x += speed;
		}
	}
}

void Player::Draw()
{
	if (colorSelected)
	{
		drawColor = playerColor;
	}
	else
	{
		drawColor = color[colorIndex];
	}

	DrawRectangle(position.x, position.y, 50, 50, drawColor);
}
