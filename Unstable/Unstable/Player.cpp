#include "Player.h"
#include "Menu.h"

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
			std::cout << "you have clicked C to change the color " << std::endl;

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
		velocity.y += gravity * gravityDirection;
		position.y += velocity.y;
		if(gravityDirection < 0)
		{
			if (position.y <= 115)
			{
				velocity = { 0, 0 };
				position.y = 115;
			}
		}
		else
		{
			if (position.y >= 825)
			{
				velocity = { 0, 0 };
				position.y = 825;
			}
		}
		if(position.x <= 0)
		{
			position.x = 0;
		}
		if(position.x >= 1050)
		{
			position.x = 1050;
		}
		if (position.y < 0)
		{
			position.y = 0;
		}

		if (IsKeyPressed(KEY_SPACE) )
		{
			if (canSwitchGravity)
			{
				// Level 3: Switch gravity direction
				gravityDirection *= -1.0f;
				velocity.y = 0;
			}
			else
			{
				// Levels 1 and 2: Normal jumping
				velocity.y = jumpForce;
			}

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
	DrawPart(2, -115, 15, 15);  // Head
	DrawPart(-7, -100, 32, 50); // Body
	DrawPart(15, -60, 10, 30);  // Right leg
	DrawPart(-7, -60, 10, 30);  // Left leg
}

void Player::DrawIdle()
{
	//DrawBody();
	if ((frame / 10) % 2 == 0)
	{
		DrawPart(2, -115, 15, 15);
		DrawPart(-7, -100, 32, 50);
		DrawPart(15, -60, 10, 30);
		DrawPart(-7, -60, 10, 30);
	}
	else
	{
		DrawPart(2, -105, 15, 15);
		DrawPart(-7, -90, 32, 50);
		DrawPart(15, -50, 10, 20);
		DrawPart(-7, -50, 10, 20);
	}
	
}

void Player::DrawJumping()
{
	DrawBody();
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
	if ((frame / 10) % 2 == 0)//animation chnages every 10 frames
	{
		DrawPart(2, -115, 15, 15);
		DrawPart(-7, -100, 32, 50);
		DrawPart(15, -60, 10, 30);
		DrawPart(-7, -60, 10, 20);
	}
	else
	{
		DrawPart(2, -115, 15, 15);
		DrawPart(-7, -100, 32, 50);
		DrawPart(15, -60, 10, 20);
		DrawPart(-7, -60, 10, 30);
	}
}

void Player::DrawPart(float t_xOffset, float t_yOffset, float t_width, float t_height)
{
	float drawY;

	if (gravityDirection == 1.0f)//if gravity is normal, draw the player normally
	{
		drawY = position.y + t_yOffset;
	}
	else // if the gravity is -1 its upside down
	{
		drawY = position.y - 145 - t_yOffset - t_height;//145 is totla hight
	}

	DrawRectangle((int)(position.x + t_xOffset),(int)drawY,(int)t_width,(int)t_height,drawColor);
}

void Player::SetPosition(Vector2 t_position)
{
	position = t_position;
}

Vector2 Player::GetPosition()
{
	return position;
}
Vector2 Player::GetVelocity()
{
	return velocity;
}

void Player::SetVelocity(Vector2 t_velocity)
{
	velocity = t_velocity;		
}

void Player::SetGravityDirection(float t_direction)
{
	gravityDirection = t_direction;

}

void Player::SetGravitySwitchEnabled(bool t_enabled)
{
	canSwitchGravity = t_enabled;

}


