#pragma once
#include <raylib.h>

class LevelButton
{
private:
	const char* text;
	int w;
	int h;
	int x;
	int y;
	Color color;

public:
	LevelButton(int x, int y, int w, int h, const char* text, Color color);

	void Draw();
	void SetColor(Color c);

	int GetPosX() const;
	int GetPosY() const;
	int GetHeight() const;

	bool completed;
	bool starCoinCollected;
};