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
	virtual void Update(unsigned int frame);
	virtual void Draw() = 0;
	float GetPosX() const;
	float GetPosY() const;
	ObstacleType GetType() const;
	void SetColor(Color c);
	

};