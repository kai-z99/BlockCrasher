#pragma once
#include <raylib.h>
#include "ObstacleTypes.h"


class Obstacle
{

protected:
	Vector2 obstaclePosition;
	ObstacleType type;
	Color color;

public:
	virtual void Draw() = 0;
	float GetPosX();
	float GetPosY();
	ObstacleType GetType() const;
	void SetColor(Color c);
	

};