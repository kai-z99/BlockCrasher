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
	Color color;
	bool isBoosting;
	float hitboxRadius;

public:
	Player(float x, float y);
	void Move(float x, float y);
	void Draw();
	void SetDirection(Direction d);
	void HandleMovement();
	void SetColor(Color c);
	void SetPosition(Vector2 pos);
	float GetPosX();
	float GetPosY();
	float GetHitboxRadius();
};