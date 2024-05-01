#include "CollisionManager.h"


bool CollisionManager::CheckCircleObstacleCollisions(Player* p, CircleObstacle* c)
{
	Vector2 playerPos = {p->GetPosX(), p->GetPosY()};
	Vector2 obstaclePos = {c->GetPosX(), c->GetPosY()};

	return CheckCollisionCircles(playerPos, p->GetHitboxRadius(), obstaclePos, c->GetRadius());
}

bool CollisionManager::CheckCollisions(Player* p, std::vector<Obstacle*> ObstacleList)
{
	for (Obstacle* ob : ObstacleList)
	{
		switch (ob->GetType())
		{
		case Circle:
			return CheckCircleObstacleCollisions(p, dynamic_cast<CircleObstacle*>(ob));
			break;

		default:
			return false;
			break;
		}
	}
}
