#include "LevelButton.h"

LevelButton::LevelButton(float x, float y, float w, float h, const char* text, int level, Color color)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->text = text;
	this->level = level;
	this->color = color;
	this->textDimensions = MeasureTextEx(GetFontDefault(), this->text, 50.0f, 0.0f);
}

void LevelButton::Draw()
{
	DrawRectangleLines(this->x, this->y, this->w, this->h, this->color);
	DrawText(this->text, this->x + 10.0f, this->y + 9.0f, 50.0f, this->color);
}

void LevelButton::SetColor(Color c)
{
	this->color = c;
}

int LevelButton::GetLevel() const
{
	return this->level;
}

float LevelButton::GetPosX() const
{
	return this->x;
}

float LevelButton::GetPosY() const
{
	return this->y;
}

float LevelButton::GetHeight() const
{
	return this->h;
}


