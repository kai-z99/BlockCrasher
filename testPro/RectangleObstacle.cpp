#include <raylib.h>
#include "RectangleObstacle.h"


RectangleObstacle::RectangleObstacle(float x, float y, float w, float h, Vector2 vi)
{
	this->obstaclePosition = { x,y };
	this->width = w;
	this->height = h;
	this->color = WHITE;
	this->type = DynamicRectangle;
	this->velocity = vi;
}

void RectangleObstacle::Draw()
{
	DrawRectangleLines((int)this->obstaclePosition.x, (int)this->obstaclePosition.y, (int)this->width, (int)this->height, this->color);
}

void RectangleObstacle::Update(unsigned int frame)
{
	this->obstaclePosition.x += this->velocity.x;
	this->obstaclePosition.y += this->velocity.y;

}

float RectangleObstacle::GetWidth()
{
	return this->width;
}

float RectangleObstacle::GetHeight()
{
	return this->height;
}
