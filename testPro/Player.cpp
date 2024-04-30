#include "player.h"


Player::Player(float x, float y)
{
	this->currentPosition = { x,y };
	this->currentDirection = N;
	this->movementHandler = PlayerMovementHandler();
}

void Player::Move(double x, double y)
{
	this->currentPosition.x += x;
	this->currentPosition.y += y;
}

void Player::Draw()
{
	Vector2 o = { 0,0 };
	Rectangle Rec = { this->currentPosition.x, this->currentPosition.y, 30.0f, 30.0f };

	switch (this->currentDirection)
	{
	case N:
		DrawRectanglePro(Rec, o, 0, RED);
		break;

	default:
		DrawRectanglePro(Rec, o, 0, GREEN);
		
	}
}

void Player::SetDirection(Direction d)
{
	this->currentDirection = d;
}

void Player::HandleMovement()
{
	this->movementHandler.HandlePlayerMovement(this);
}
