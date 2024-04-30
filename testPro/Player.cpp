#include "player.h"
#include <cmath>

Player::Player(float x, float y)
{
	this->currentPosition = { x,y };
	this->currentDirection = N;
	this->movementHandler = PlayerMovementHandler();
	this->isBoosting = false;
}

void Player::Move(double x, double y)
{
	this->currentPosition.x += x;
	this->currentPosition.y += y;
}

void Player::Draw()
{
	Vector2 v1;
	Vector2 v2;
	Vector2 v3;

	float HITBOX_SCALE = 10.0;
	float x = this->currentPosition.x;
	float y = this->currentPosition.y;

	switch (this->currentDirection)
	{
	case N:
		v1 = { x + 10, y };
		v2 = { x, y - 20 };
		v3 = { x - 10, y };
		break;

	case NE:
		v1 = { x + (20 * cos(PI / 4)), y - (20 * sin(PI / 4)) };
		v2 = { x + (-10 * cos(PI / 4)), y - (10 * sin(PI / 4)) };
		v3 = { x + (10 * cos(PI / 4)), y - (-10 * sin(PI / 4)) };
		break;

	case E:
		v1 = { x, y + 10 };
		v2 = { x + 20, y };
		v3 = { x, y - 10 };
		break;

	case SE:
		v1 = { x + (20 * cos(PI / 4)), y - (-20 * sin(PI / 4)) };
		v2 = { x + (10 * cos(PI / 4)), y - (10 * sin(PI / 4)) };
		v3 = { x + (-10 * cos(PI / 4)), y - (-10 * sin(PI / 4)) };
		break;


	case S:
		v1 = { x - 10, y };
		v2 = { x, y + 20 };
		v3 = { x + 10, y };
		break;

	case SW:
		v1 = { x + (-20 * cos(PI / 4)), y - (-20 * sin(PI / 4)) };
		v2 = { x + (10 * cos(PI / 4)), y - (-10 * sin(PI / 4)) };
		v3 = { x + (-10 * cos(PI / 4)), y - (10 * sin(PI / 4)) };
		break;

	case W:
		v1 = { x, y - 10 };
		v2 = { x - 20, y };
		v3 = { x, y + 10 };
		break;

	case NW:
		v1 = { x + (-20 * cos(PI / 4)), y - (20 * sin(PI / 4)) };
		v2 = { x + (-10 * cos(PI / 4)), y - (-10 * sin(PI / 4)) };
		v3 = { x + (10 * cos(PI / 4)), y - (10 * sin(PI / 4)) };
		break;

	default:
		v1 = { this->currentPosition.x, this->currentPosition.y + 10 };
		v2 = { this->currentPosition.x + 20, this->currentPosition.y };
		v3 = { this->currentPosition.x, this->currentPosition.y - 10 };
		break;
	}

	
	

	DrawTriangle(v1, v2, v3, WHITE);
}

void Player::SetDirection(Direction d)
{
	this->currentDirection = d;
}

void Player::HandleMovement()
{
	this->movementHandler.HandlePlayerMovement(this);
}
