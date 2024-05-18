#include "Obstacle.h"


float Obstacle::GetPosX() const
{
    return this->obstaclePosition.x;
}

float Obstacle::GetPosY() const
{
    return this->obstaclePosition.y;
}

Vector2 Obstacle::GetVelocity() const
{
    return this->velocity;
}

void Obstacle::SetPosX(float x)
{
    this->obstaclePosition.x = x;
}

void Obstacle::SetPosY(float y)
{
    this->obstaclePosition.y = y;
}

ObstacleType Obstacle::GetType() const
{
    return this->type;
}

void Obstacle::SetCurrentColor(Color c)
{
    this->color = c;
}

void Obstacle::SetVelocity(float x, float y)
{
    this->velocity.x = x;
    this->velocity.y = y;
}

