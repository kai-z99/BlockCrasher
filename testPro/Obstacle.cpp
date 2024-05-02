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

ObstacleType Obstacle::GetType() const
{
    return this->type;
}

void Obstacle::SetColor(Color c)
{
    this->color = c;
}

