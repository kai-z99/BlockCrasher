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
	Color color;

public:
	LevelButton(int x, int y, int w, int h, const char* text, Color color);

	void Draw();
	void SetColor(Color c);

	float GetPosX() const;
	float GetPosY() const;
	float GetHeight() const;

	bool completed;
	bool starCoinCollected;
};