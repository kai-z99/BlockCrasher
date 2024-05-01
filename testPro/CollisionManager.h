#pragma once
#include <vector>
#include <raylib.h>
#include "Player.h"
#include "Obstacle.h"
#include "CircleObstacle.h"
#include "StaticRectangleObstacle.h"


class CollisionManager
{

private:
	bool CheckCircleObstacleCollisions(Player* p, CircleObstacle* c);
	bool CheckStaticRectangleObstacleCollisions(Player* p, StaticRectangleObstacle* s);

public:
	bool CheckCollisions(Player* p, std::vector<Obstacle*> ObstacleList);
	
};