#include <cmath>
#include "player.h"


Player::Player(float x, float y)
{
	this->currentPosition = { x,y };
	this->currentDirection = N;
	this->hitboxRadius = 7;
	this->color = BLUE;
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


    const float HITBOX_SCALE = 10.0;
    const float TRIANGLE_BASE = 10.0;
    const float TRIANGLE_HEIGHT = 20.0;

    float x = this->currentPosition.x;
    float y = this->currentPosition.y;

    // calculate a offset to position the player at the center
    float offset = (TRIANGLE_HEIGHT) / 3.0;
    float diagonalOffset = offset / sqrt(2);

    switch (this->currentDirection)
    {
    case N:
        v1 = { x + TRIANGLE_BASE, y + offset };
        v2 = { x, y - TRIANGLE_HEIGHT + offset };
        v3 = { x - TRIANGLE_BASE, y + offset };
        break;

    case NE:
        v1 = { x + (TRIANGLE_HEIGHT * cos(PI / 4)) - diagonalOffset, y - (TRIANGLE_HEIGHT * sin(PI / 4)) + diagonalOffset };
        v2 = { x + (-TRIANGLE_BASE * cos(PI / 4)) - diagonalOffset, y - (TRIANGLE_BASE * sin(PI / 4)) + diagonalOffset };
        v3 = { x + (TRIANGLE_BASE * cos(PI / 4)) - diagonalOffset, y - (-TRIANGLE_BASE * sin(PI / 4)) + diagonalOffset };
        break;

    case E:
        v1 = { x - offset, y + TRIANGLE_BASE };
        v2 = { x + TRIANGLE_HEIGHT - offset, y };
        v3 = { x - offset, y - TRIANGLE_BASE };
        break;

    case SE:
        v1 = { x + (TRIANGLE_HEIGHT * cos(PI / 4)) - diagonalOffset, y - (-TRIANGLE_HEIGHT * sin(PI / 4)) - diagonalOffset };
        v2 = { x + (TRIANGLE_BASE * cos(PI / 4)) - diagonalOffset, y - (TRIANGLE_BASE * sin(PI / 4)) - diagonalOffset };
        v3 = { x + (-TRIANGLE_BASE * cos(PI / 4)) - diagonalOffset, y - (-TRIANGLE_BASE * sin(PI / 4)) - diagonalOffset };
        break;

    case S:
        v1 = { x - TRIANGLE_BASE, y - offset };
        v2 = { x, y + TRIANGLE_HEIGHT - offset };
        v3 = { x + TRIANGLE_BASE, y - offset };
        break;

    case SW:
        v1 = { x + (-TRIANGLE_HEIGHT * cos(PI / 4)) + diagonalOffset, y - (-TRIANGLE_HEIGHT * sin(PI / 4)) - diagonalOffset };
        v2 = { x + (TRIANGLE_BASE * cos(PI / 4)) + diagonalOffset, y - (-TRIANGLE_BASE * sin(PI / 4)) - diagonalOffset };
        v3 = { x + (-TRIANGLE_BASE * cos(PI / 4)) + diagonalOffset, y - (TRIANGLE_BASE * sin(PI / 4)) - diagonalOffset };
        break;

    case W:
        v1 = { x + offset, y - TRIANGLE_BASE };
        v2 = { x - TRIANGLE_HEIGHT + offset, y };
        v3 = { x + offset, y + TRIANGLE_BASE };
        break;

    case NW:
        v1 = { x + (-TRIANGLE_HEIGHT * cos(PI / 4)) + diagonalOffset, y - (TRIANGLE_HEIGHT * sin(PI / 4)) + diagonalOffset };
        v2 = { x + (-TRIANGLE_BASE * cos(PI / 4)) + diagonalOffset, y - (-TRIANGLE_BASE * sin(PI / 4)) + diagonalOffset };
        v3 = { x + (TRIANGLE_BASE * cos(PI / 4)) + diagonalOffset, y - (TRIANGLE_BASE * sin(PI / 4)) + diagonalOffset };
        break;

    default:
        v1 = { this->currentPosition.x, this->currentPosition.y + TRIANGLE_BASE };
        v2 = { this->currentPosition.x + TRIANGLE_HEIGHT, this->currentPosition.y };
        v3 = { this->currentPosition.x, this->currentPosition.y - TRIANGLE_BASE };
        break;
    }

    DrawTriangleLines(v1, v2, v3, this->color);
	//DrawTriangle(v1, v2, v3, this->color);
	
	
	//Rectangle tailRec = { x, y, 10, 10 }; // Centering the rectangle on x, y
	//Vector2 tailOrigin = { 5, 5 }; // Origin at the center of the rectangle

	//float rotation = 0;
	//if (this->currentDirection == NE || this->currentDirection == SE || this->currentDirection == SW || this->currentDirection == NW)
	//{
	//	rotation = 45;
	//}

	//DrawRectanglePro(tailRec, tailOrigin, rotation, this->color);
}

void Player::DrawHitbox()
{
	DrawCircleLines(this->currentPosition.x , this->currentPosition.y, this->hitboxRadius, RED);
    // Draw the central point
    DrawCircleLines(this->currentPosition.x, this->currentPosition.y, 1, GREEN);

    // Draw the right point
    DrawCircleLines(this->currentPosition.x + 5, this->currentPosition.y, 1, GREEN);

    // Draw the left point
    DrawCircleLines(this->currentPosition.x - 5, this->currentPosition.y, 1, GREEN);

    // Draw the upper point
    DrawCircleLines(this->currentPosition.x, this->currentPosition.y + 5, 1, GREEN);

    // Draw the lower point
    DrawCircleLines(this->currentPosition.x, this->currentPosition.y - 5, 1, GREEN);
}

void Player::SetDirection(Direction d)
{
	this->currentDirection = d;
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
