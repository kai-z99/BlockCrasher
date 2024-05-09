#pragma once
#include <raylib.h>
#include "Directions.h"


class Player
{
private:
	Vector2 currentPosition;
	Direction currentDirection;
	Color color;
	float hitboxRadius;
	

public:
	Player(float x, float y);
	void Move(float x, float y);
	void SetPosition(Vector2 pos);
	void SetDirection(Direction d);
	void SetColor(Color c);

	void Draw();
	void DrawHitbox(); // debug use only DRAWS CIRCLE HITBOX IN RED, POINT HITBOX IN GREEN

	float GetPosX();
	float GetPosY();
	float GetHitboxRadius();
};