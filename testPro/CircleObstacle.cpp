#include "CircleObstacle.h"

CircleObstacle::CircleObstacle(float x, float y, float r, Vector2 v)
{
	this->obstaclePosition = { x,y };
	this->radius = r;
	this->color = WHITE;
	this->type = Circle;
	this->velocity = v;
}

void CircleObstacle::Draw()
{
	DrawCircleLines((int)this->obstaclePosition.x, (int)this->obstaclePosition.y, this->radius, this->color);
}

void CircleObstacle::Update(unsigned int frame)
{
	this->obstaclePosition.x += this->velocity.x;
	this->obstaclePosition.y += this->velocity.y;
}

float CircleObstacle::GetRadius() const
{
	return this->radius;
}
