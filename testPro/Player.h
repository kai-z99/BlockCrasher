#pragma once
#include <raylib.h>
#include "Directions.h"
#include "PlayerMovementHandler.h"

class Player
{
private:
	PlayerMovementHandler movementHandler;
	Vector2 currentPosition;
	Direction currentDirection;

public:
	Player(float x, float y);
	void Move(double x, double y);
	void Draw();
	void SetDirection(Direction d);
	void HandleMovement();
};