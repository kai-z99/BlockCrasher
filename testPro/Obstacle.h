#pragma once
#include <raylib.h>
#include "ObstacleTypes.h"


class Obstacle
{

protected:
	Vector2 obstaclePosition;
	ObstacleType type;
	Color color;
	Vector2 velocity;

public:
	virtual void Update(unsigned int frame) = 0;
	virtual void Draw() = 0;
	float GetPosX() const;
	float GetPosY() const;
	Vector2 GetVelocity() const;
	ObstacleType GetType() const;

	void SetPosX(float x);
	void SetPosY(float y);
	void SetColor(Color c);
	void SetVelocity(float x, float y);
	

};