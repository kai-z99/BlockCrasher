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

public:
	LevelButton(int x, int y, int w, int h, const char* text, int level, Color color);

	void Draw();
	void SetColor(Color c);

	int GetLevel() const;
	float GetPosX() const;
	float GetPosY() const;
	float GetHeight() const;

	bool completed;
	bool starCoinCollected;
};