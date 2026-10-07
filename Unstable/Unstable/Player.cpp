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
