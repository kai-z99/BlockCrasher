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
	void SetCurrentColor(Color c); // from a color obj
	void SetSelectedColorIndex(int index); // for memory
	void RotateColorChannels(int type); // 0 is from currentColor, 1 is from selectedColor.
	
	int GetColorCount();

	void Draw();
	void DrawHitbox(); // debug use only DRAWS CIRCLE HITBOX IN RED, POINT HITBOX IN GREEN

	float GetPosX();
	float GetPosY();
	float GetHitboxRadius();
	Color GetCurrentColor() const;
	

	int selectedColorIndex;
};