#include <iostream>
#include "CollisionManager.h"
#include "Player.h"
#include "CircleObstacle.h"
#include "RectangleObstacle.h"
#include "DynamicShapeObstacle.h"


bool CollisionManager::CheckCircleObstacleCollisions(Player* p, CircleObstacle* c)
{
	Vector2 playerPos = {p->GetPosX(), p->GetPosY()};
	Vector2 obstaclePos = {c->GetPosX(), c->GetPosY()};

	return CheckCollisionCircles(playerPos, p->GetHitboxRadius(), obstaclePos, c->GetRadius());
}

bool CollisionManager::CheckStaticRectangleObstacleCollisions(Player* p, RectangleObstacle* s)
{
	/*Vector2 playerPos = { p->GetPosX(), p->GetPosY() };
	Rectangle rec = { s->GetPosX() - (s->GetWidth()/2), s->GetPosY() - (s->GetHeight()/2), s->GetWidth(), s->GetHeight()};

	return CheckCollisionCircleRec(playerPos, p->GetHitboxRadius(), rec);*/

	Rectangle rec = { s->GetPosX(), s->GetPosY(), s->GetWidth(), s->GetHeight() };
	Vector2 playerPos = { p->GetPosX(), p->GetPosY() };
	return CheckCollisionPointRec(playerPos, rec);
}

bool CollisionManager::CheckDynamicShapeObstacleCollisions(Player* p, DynamicShapeObstacle* d)
{
	return CheckCollisionPointPoly({ p->GetPosX(), p->GetPosY() }, &d->GetVertices()[0], d->GetVertices().size());
}

bool CollisionManager::CheckCollisions(Player* p, std::vector<Obstacle*> ObstacleList)
{
	for (Obstacle* ob : ObstacleList)
	{
		//Depending on ObstacleType, check collisions.
		switch (ob->GetType())
		{
		case Circle:
			if (CheckCircleObstacleCollisions(p, dynamic_cast<CircleObstacle*>(ob)))
			{
				return true;
			}
			break;

		case DynamicRectangle:
			if (CheckStaticRectangleObstacleCollisions(p, dynamic_cast<RectangleObstacle*>(ob)))
			{
				return true;
			}
			break;

		case DynamicShape:
			if (CheckDynamicShapeObstacleCollisions(p, dynamic_cast<DynamicShapeObstacle*>(ob)))
			{
				return true;
			}
			break;

		default:
			break;
		}
	}

	return false;
}
