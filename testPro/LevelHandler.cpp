#include "Constants.h"
#include "LevelHandler.h"
#include "ObstacleBuilder.h"


LevelHandler::LevelHandler()
{
	this->obstacleBuilder = new ObstacleBuilder();
	this->currentLevel = 1;
	this->totalCoinsInLevel = 1;
	this->coinsCollectedInLevel = 0;
	this->currentLevelFramecount = 0;
	this->currentLevelComplete = false;
	this->levelFail = false;
	this->playerSpawnpoint = { 0,0 };
}

void LevelHandler::LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles)
{
	this->currentLevelComplete = false;
	this->levelFail = false;

	switch (this->currentLevel)
	{
	case 1:
		this->playerSpawnpoint = { 100,100 };
		this->obstacleBuilder->MasterSword((screenWidth / 2) - 50, (screenHeight / 2) - 200); // 0
		this->obstacleBuilder->ClassicCircle(300, 600, 50, { -1,1 });
		this->obstacleBuilder->ClassicCircle(600, 600, 50, { 1,-1 });
		this->obstacleBuilder->ClassicCircle(600, 300, 50, { 1,1 });
		break;

	case 2:
		this->playerSpawnpoint = { 50,50 };
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

	this->coinsCollectedInLevel = 0;
	this->totalCoinsInLevel = 0;
	this->currentLevelFramecount = 0;
}

void LevelHandler::HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles)
{
	this->currentLevelFramecount += 1;

	if (this->levelFail)
	{
		this->UnloadCurrentLevel(activeObstacles);
		this->LoadCurrentLevel(activeObstacles);
	}

	else if (this->coinsCollectedInLevel >= this->totalCoinsInLevel)
	{
		this->currentLevelComplete = true;
	}
}

void LevelHandler::SetLevel(int l)
{
	this->currentLevel = l;
}

void LevelHandler::FailCurrentLevel()
{
	this->levelFail = true;
}

void LevelHandler::AddCoinCollected(int amount)
{
	this->coinsCollectedInLevel += amount;
}

unsigned int LevelHandler::GetCurrentLevelFramecount() const
{
	return this->currentLevelFramecount;
}

Vector2 LevelHandler::GetPlayerSpawnpoint() const
{
	return this->playerSpawnpoint;
}
