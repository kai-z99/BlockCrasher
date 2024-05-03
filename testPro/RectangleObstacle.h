#pragma once
#include "Obstacle.h"

class RectangleObstacle : public Obstacle
{
public:
	RectangleObstacle(float x, float y, float w, float h, Vector2 vi);
	void Draw() override;
	void Update(unsigned int frame) override;
	float GetWidth();
	float GetHeight();

private:
	float width;
	float height;
};