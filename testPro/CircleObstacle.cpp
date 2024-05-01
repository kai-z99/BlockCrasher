#include "CircleObstacle.h"

CircleObstacle::CircleObstacle(float x, float y, float r)
{
	this->obstaclePosition = { x,y };
	this->radius = r;
	this->type = Circle;
}

void CircleObstacle::Draw()
{
	DrawCircle(this->obstaclePosition.x, this->obstaclePosition.y, this->radius, WHITE);
}

float CircleObstacle::GetRadius()
{
	return this->radius;
}
