#include "Obstacle.h"

void Obstacle::Update(unsigned int frame)
{
}

float Obstacle::GetPosX() const
{
    return this->obstaclePosition.x;
}

float Obstacle::GetPosY() const
{
    return this->obstaclePosition.y;
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

void Obstacle::SetColor(Color c)
{
    this->color = c;
}

void Obstacle::SetVelocity(float x, float y)
{
    this->velocity.x = x;
    this->velocity.y = y;
}

