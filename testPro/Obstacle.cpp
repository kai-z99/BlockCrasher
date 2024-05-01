#include "Obstacle.h"

float Obstacle::GetPosX()
{
    return this->obstaclePosition.x;
}

float Obstacle::GetPosY()
{
    return this->obstaclePosition.y;
}

ObstacleType Obstacle::GetType()
{
    return this->type;
}

