#pragma once
#include <vector>
#include <raylib.h>

class Obstacle;

class ObstacleBuilder
{
private:
	std::vector<Obstacle*> storage;
public:
	void Insert(std::vector<Obstacle*>& activeObstacles );
	void FlyingPentagon(float x, float y);
	void ClassicCircle(float x, float y, float r, Vector2 vi);
	void ClassicRectangle(float x, float y, float w, float h, Vector2 vi);

};