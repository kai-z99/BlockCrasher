#include "Constants.h"
#include "LevelHandler.h"
#include "ObstacleBuilder.h"


LevelHandler::LevelHandler()
{
	this->obstacleBuilder = new ObstacleBuilder();
	this->currentLevel = 1;
}

void LevelHandler::LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles)
{
	switch (this->currentLevel)
	{
	case 1:
		this->obstacleBuilder->MasterSword((screenWidth / 2) - 50, (screenHeight / 2) - 200); // 0
		this->obstacleBuilder->ClassicCircle(300, 600, 50, { -1,1 });
		this->obstacleBuilder->ClassicCircle(600, 600, 50, { 1,-1 });
		this->obstacleBuilder->ClassicCircle(600, 300, 50, { 1,1 });
		break;

	case 2:
		this->obstacleBuilder->FlyingPentagon(300,300);
		this->obstacleBuilder->ClassicCircle(600, 600, 50, {1,1});
		this->obstacleBuilder->ClassicRectangle(500, 500, 60, 40, { 0,0 });
		break;

	default:
		break;

	}

	this->obstacleBuilder->Insert(activeObstacles);
}

void LevelHandler::UnloadCurrentLevel(std::vector<Obstacle*>& activeObstacles)
{
	for (Obstacle* ob : activeObstacles)
	{
		delete ob;
	}

	activeObstacles.clear();
}

void LevelHandler::HandleCurrentLevel()
{
}

void LevelHandler::SetLevel(int l)
{
	this->currentLevel = l;
}
