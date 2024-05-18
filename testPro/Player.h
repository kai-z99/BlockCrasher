#pragma once
#include <raylib.h>
#include <vector>
#include "Directions.h"



class Player
{
private:
	Vector2 currentPosition;
	Direction currentDirection;
	std::vector<Color> colors; // temp?
	Color currentColor;
	float hitboxRadius;
	

public:
	Player(float x, float y);
	void Move(float x, float y);
	void SetPosition(Vector2 pos);
	void SetDirection(Direction d);
	void SetCurrentColor(int index); // from the colors vector
	void SetSelectedColorIndex(int index); // for memory
	int GetColorCount();

	void Draw();
	void DrawHitbox(); // debug use only DRAWS CIRCLE HITBOX IN RED, POINT HITBOX IN GREEN

	float GetPosX();
	float GetPosY();
	float GetHitboxRadius();

	int selectedColorIndex;
};