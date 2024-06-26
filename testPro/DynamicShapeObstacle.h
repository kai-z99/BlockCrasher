#pragma once
#include <raylib.h>
#include <vector>
#include "Obstacle.h"


class DynamicShapeObstacle : public Obstacle
{
public:
	DynamicShapeObstacle(float x, float y, Vector2 c, const std::vector<Vector2>& v, float rr, float vo, Vector2 vi, float ri);
	void Draw() override;
	void Update(unsigned int frame) override;
	void SetPosX(float x) override; //ovveride
	void SetPosY(float y) override; //override
	std::vector<Vector2> GetVertices() const;

private:
	std::vector<Vector2> vertices;
	Vector2 center;
	float rotationRate;
	float volatility; //how fast rotation changes directions
	

};