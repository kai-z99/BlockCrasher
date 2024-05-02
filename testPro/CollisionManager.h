#pragma once
#include <vector>
#include <raylib.h>
#include "Player.h"

class Obstacle;
class CircleObstacle;
class StaticRectangleObstacle;


class CollisionManager
{

private:
	//Collision checks for different Obstacles
	bool CheckCircleObstacleCollisions(Player* p, CircleObstacle* c);
	bool CheckStaticRectangleObstacleCollisions(Player* p, StaticRectangleObstacle* s);

public:

	//Check collisions of every object, collision function based on ObstacleType enum
	bool CheckCollisions(Player* p, std::vector<Obstacle*> ObstacleList);
	
};