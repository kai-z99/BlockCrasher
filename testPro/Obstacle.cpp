#include "Obstacle.h"

float Obstacle::GetPosX()
{
    return this->obstaclePosition.x;
}

float Obstacle::GetPosY()
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

