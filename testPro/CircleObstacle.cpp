#include "CircleObstacle.h"

CircleObstacle::CircleObstacle(float x, float y, float r)
{
	this->obstaclePosition = { x,y };
	this->radius = r;
	this->color = WHITE;
	this->type = Circle;
}

void CircleObstacle::Draw()
{
	DrawCircle((int)this->obstaclePosition.x, (int)this->obstaclePosition.y, this->radius, this->color);
}

float CircleObstacle::GetRadius() //why??/ when make const
{
	return this->radius;
}
