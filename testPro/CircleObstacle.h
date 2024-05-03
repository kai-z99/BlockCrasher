#pragma once
#include "Obstacle.h"

class CircleObstacle : public Obstacle
{
public:
	CircleObstacle(float x, float y, float r, Vector2 v);
	void Draw() override;
	void Update(unsigned int frame) override;
	float GetRadius() const;

private:
	float radius;
};