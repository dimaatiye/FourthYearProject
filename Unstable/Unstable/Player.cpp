#include "Player.h"

Player::Player()
{

}

void Player::Update()
{
	frame++;
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
			state = PlayerState::Jumping;
			std::cout << "player jumping " << std::endl;


		}
		else if (IsKeyDown(KEY_LEFT))
		{
			state = PlayerState::WalkLeft;
			std::cout << "player moving left " << std::endl;

		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			state = PlayerState::WalkRight;
			std::cout << "player moving right " << std::endl;
			
		}
		else {
			state = PlayerState::Idle;
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

	switch (state)
	{
	case PlayerState::Idle:
		DrawIdle();
		break;
	case PlayerState::Jumping:
		DrawJumping();
		break;
	case PlayerState::WalkLeft:
		DrawWalkLeft();
		break;
	case PlayerState::WalkRight:
		DrawWalkRight();
		break;

	}
}

void Player::DrawBody()
{
	DrawRectangle(position.x + 2, position.y - 115, 15, 15, drawColor);// head
	DrawRectangle(position.x - 7, position.y - 100, 32, 50, drawColor);//boddy
	DrawRectangle(position.x + 15, position.y - 60, 10, 30, drawColor); // right leg
	DrawRectangle(position.x - 7, position.y - 60, 10, 30, drawColor);// left leg
}

void Player::DrawIdle()
{
	//DrawBody();
	if ((frame / 10) % 2 == 0)//switch between two animation frames every 10 frames
	{
		DrawRectangle(position.x + 2, position.y - 115, 15, 15, drawColor);// head
		DrawRectangle(position.x - 7, position.y - 100, 32, 50, drawColor);//boddy
		DrawRectangle(position.x + 15, position.y - 60, 10, 30, drawColor); // right leg
		DrawRectangle(position.x - 7, position.y - 60, 10, 30, drawColor);// left leg
		std::cout << "frame: " << frame << std::endl;
	}
	else
	{
		DrawRectangle(position.x + 2, position.y - 105, 15, 15, drawColor);// head
		DrawRectangle(position.x - 7, position.y - 90, 32, 50, drawColor);//boddy
		DrawRectangle(position.x + 15, position.y - 50, 10, 20, drawColor); // right leg
		DrawRectangle(position.x - 7, position.y - 50, 10, 20, drawColor);// left leg
	}
	
}

void Player::DrawJumping()
{
	DrawBody();
	velocity.y += jumpForce;
}

void Player::DrawWalkLeft()
{
	//DrawBody();
	position.x -= speed;
	DrawWalking();
}

void Player::DrawWalkRight()
{
	//DrawBody();
	position.x += speed;
	DrawWalking();

}

void Player::DrawWalking()
{
	if ((frame / 10) % 2 == 0)//switch between two animation frames every 10 frames
	{
		DrawRectangle(position.x + 2, position.y - 115, 15, 15, drawColor);// head
		DrawRectangle(position.x - 7, position.y - 100, 32, 50, drawColor);//boddy
		DrawRectangle(position.x + 15, position.y - 60, 10, 30, drawColor); // right leg
		DrawRectangle(position.x - 7, position.y - 60, 10, 20, drawColor);// left leg
		std::cout << "frame: " << frame << std::endl;
	}
	else
	{
		DrawRectangle(position.x + 2, position.y - 115, 15, 15, drawColor);// head
		DrawRectangle(position.x - 7, position.y - 100, 32, 50, drawColor);//boddy
		DrawRectangle(position.x + 15, position.y - 60, 10, 20, drawColor); // right leg
		DrawRectangle(position.x - 7, position.y - 60, 10, 30, drawColor);// left leg
	}
}

