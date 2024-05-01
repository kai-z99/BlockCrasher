#include <raylib.h>
#include "StaticRectangleObstacle.h"


StaticRectangleObstacle::StaticRectangleObstacle(float x, float y, float w, float h)
{
	this->obstaclePosition = { x,y };
	this->width = w;
	this->height = h;
	this->color = WHITE;
	this->type = StaticRectangle;
}

void StaticRectangleObstacle::Draw()
{
	Rectangle rec = { this->obstaclePosition.x, this->obstaclePosition.y, this->width, this->height };
	Vector2 origin = { this->width / 2, this->height / 2 };

	DrawRectanglePro(rec, origin, 0, this->color);
}

float StaticRectangleObstacle::GetWidth()
{
	return this->width;
}

float StaticRectangleObstacle::GetHeight()
{
	return this->height;
}
