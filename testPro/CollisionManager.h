#pragma once
#include <vector>
#include <raylib.h>


class Player;
class Obstacle;
class CircleObstacle;
class StaticRectangleObstacle;
class DynamicShapeObstacle;


class CollisionManager
{

private:
	//Collision checks for different Obstacles
	bool CheckCircleObstacleCollisions(Player* p, CircleObstacle* c);
	bool CheckStaticRectangleObstacleCollisions(Player* p, StaticRectangleObstacle* s);
	bool CheckDynamicShapeObstacleCollisions(Player* p, DynamicShapeObstacle* d);

public:

	//Check collisions of every object, collision function based on ObstacleType enum
	bool CheckCollisions(Player* p, std::vector<Obstacle*> ObstacleList);
	
};