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
	/*Rectangle rec = { this->obstaclePosition.x, this->obstaclePosition.y, this->width, this->height };
	Vector2 origin = { this->width / 2, this->height / 2 };

	DrawRectanglePro(rec, origin, 0, this->color);*/

	DrawRectangleLines(this->obstaclePosition.x, this->obstaclePosition.y, this->width, this->height, this->color);
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
