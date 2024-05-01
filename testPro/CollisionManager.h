#pragma once
#include <vector>
#include <raylib.h>
#include "Player.h"
#include "CircleObstacle.h"


class CollisionManager
{

private:
	bool CheckCircleObstacleCollisions(Player* p, CircleObstacle* c);


public:
	bool CheckCollisions(Player* p, std::vector<Obstacle*> ObstacleList);
	
};