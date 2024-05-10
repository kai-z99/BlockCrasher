#include "LevelButton.h"

LevelButton::LevelButton(int x, int y, int w, int h, const char* text, Color color)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->text = text;
	this->color = color;
	this->completed = false; // will reset if we clear the vector of buttons.
	this->starCoinCollected = false; //same here.
}

void LevelButton::Draw()
{
	DrawRectangleLines(this->x, this->y, this->w, this->h, this->color);
	DrawText(this->text, this->x + 10.0f, this->y + 9.0f, 50.0f, this->color);

	Color completeCircleColor;

	if (this->starCoinCollected)
	{
		completeCircleColor = PINK;
	}

	else if (this->completed)
	{
		completeCircleColor = YELLOW;
	}

	else
	{
		completeCircleColor = BLACK;
	}

	DrawCircleLines(this->x + this->w - 20.0f, this->y + this->h / 2, 10, completeCircleColor);
	
}

void LevelButton::SetColor(Color c)
{
	this->color = c;
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


