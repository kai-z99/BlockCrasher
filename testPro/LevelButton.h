#pragma once
#include <raylib.h>



class LevelButton
{
private:
	const char* text;
	float w;
	float h;
	float x;
	float y;
	int level;
	Color color;
	Vector2 textDimensions;

public:
	LevelButton(float x, float y, float w, float h, const char* text, int level, Color color);

	void Draw();
	void SetColor(Color c);

	int GetLevel() const;
	float GetPosX() const;
	float GetPosY() const;
	float GetHeight() const;
};