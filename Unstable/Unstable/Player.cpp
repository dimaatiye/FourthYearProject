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

		if (position.y >= 825)
		{
			velocity.y = 0;
			position.y = 825;
		}
		if(position.x <= 0)
		{
			position.x = 0;
		}
		if(position.x >= 1050)
		{
			position.x = 1050;
		}
		if (IsKeyPressed(KEY_SPACE) && position.y == 825)
		{
			velocity.y += jumpForce;
			std::cout << "player jumping " << std::endl;


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

	DrawRectangle(position.x +2, position.y - 115, 15, 15, drawColor);// head
	DrawRectangle(position.x -7, position.y -100 , 32, 50, drawColor);//boddy
	DrawRectangle(position.x +15, position.y -60, 10,30, drawColor); // right leg
	DrawRectangle(position.x -7, position.y -60, 10, 30, drawColor);// left leg

}
