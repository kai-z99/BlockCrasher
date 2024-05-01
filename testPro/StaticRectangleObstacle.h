#pragma once
#include "Obstacle.h"

class StaticRectangleObstacle : public Obstacle
{
public:
	StaticRectangleObstacle(float x, float y, float w, float h);
	void Draw() override;
	float GetWidth();
	float GetHeight();

private:
	float width;
	float height;
};