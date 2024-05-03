#include <cmath>
#include "player.h"


Player::Player(float x, float y)
{
	this->currentPosition = { x,y };
	this->currentDirection = N;
	this->movementHandler = PlayerMovementHandler();
	this->isBoosting = false;
	this->hitboxRadius = 8;
	this->color = WHITE;
}

void Player::Move(float x, float y)
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

	
	
	

	DrawTriangle(v1, v2, v3, this->color);
	
	//DrawRectangle(300, 300, 50, 50, WHITE);
	//Rectangle testRec = { 600,600, 50,50};
	//Vector2 testOrigin = { 25,25 };
	//DrawRectanglePro(testRec, testOrigin, 45, WHITE);
	//DrawCircle(300, 300, 5, RED);
	//DrawCircle(600, 600, 5, BLUE);
	
	Rectangle tailRec = { x, y, 10, 10 }; // Centering the rectangle on x, y
	Vector2 tailOrigin = { 5, 5 }; // Origin at the center of the rectangle

	float rotation = 0;
	if (this->currentDirection == NE || this->currentDirection == SE || this->currentDirection == SW || this->currentDirection == NW)
	{
		rotation = 45;
	}

	DrawRectanglePro(tailRec, tailOrigin, rotation, this->color);
}

void Player::SetDirection(Direction d)
{
	this->currentDirection = d;
}

void Player::HandleMovement()
{
	this->movementHandler.HandlePlayerMovement(this);
}

void Player::SetColor(Color c)
{
	this->color = c;
}

void Player::SetPosition(Vector2 pos)
{
	this->currentPosition = pos;
}

float Player::GetPosX()
{
	return this->currentPosition.x;
}

float Player::GetPosY()
{
	return this->currentPosition.y;
}

float Player::GetHitboxRadius()
{
	return this->hitboxRadius;
}
