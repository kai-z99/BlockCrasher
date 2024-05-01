#pragma once
#include "Obstacle.h"

class CircleObstacle : public Obstacle
{
public:
	CircleObstacle(float x, float y, float r);
	void Draw() override;
	float GetRadius();

private:
	float radius;
};