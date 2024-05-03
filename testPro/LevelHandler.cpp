#include "Constants.h"
#include "LevelHandler.h"
#include "ObstacleBuilder.h"
#include "Obstacle.h"


LevelHandler::LevelHandler()
{
	this->obstacleBuilder = new ObstacleBuilder();
	this->currentLevel = 1;
	this->totalCoinsInLevel = 1;
	this->coinsCollectedInLevel = 0;
	this->currentLevelFramecount = 0;
	this->currentLevelComplete = false;
	this->playerSpawnpoint = { 0,0 };
}

void LevelHandler::LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles)
{
	switch (this->currentLevel)
	{
	case 1:
		this->playerSpawnpoint = { 100,100 };
		this->obstacleBuilder->MasterSword((screenWidth / 2) - 50, (screenHeight / 2) - 200); // 0
		// Master Sword Circle																  // 1
		this->obstacleBuilder->ClassicCircle(300, 600, 50, { -2,1 });						  // 2 
		this->obstacleBuilder->ClassicCircle(600, 600, 50, { 1,-3 });						  // 3
		this->obstacleBuilder->ClassicCircle(600, 300, 50, { 4,1 });						  // 4

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
}

void LevelHandler::HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles)
{
	this->currentLevelFramecount += 1;

	if (this->coinsCollectedInLevel >= this->totalCoinsInLevel)
	{
		this->currentLevelComplete = true;
	}

	//level specific handling
	switch (this->currentLevel)
	{
	case 1:
		//activeObstacles[0]->SetColor(GREEN);

		//Bounce the ballz on the side of the screen
		for (int i = 2; i <= 4; i++)
		{

			if (activeObstacles[i]->GetPosX() + 25 > screenWidth || activeObstacles[i]->GetPosX() - 25 < 0)
			{
				activeObstacles[i]->SetVelocity(-activeObstacles[i]->GetVelocity().x, activeObstacles[i]->GetVelocity().y);
			}

			if (activeObstacles[i]->GetPosY() + 25 > screenHeight || activeObstacles[i]->GetPosY() - 25 < 0)
			{
				activeObstacles[i]->SetVelocity(activeObstacles[i]->GetVelocity().x, -activeObstacles[i]->GetVelocity().y);
			}

		}

		break;
	case 2:
		break;
	default:
		break;
	}


}

void LevelHandler::SetLevel(int l)
{
	this->currentLevel = l;
}

void LevelHandler::AddCoinCollected(int amount)
{
	this->coinsCollectedInLevel += amount;
}

void LevelHandler::ResetCurrentLevel(std::vector<Obstacle*>& activeObstacles)
{
	this->UnloadCurrentLevel(activeObstacles);
	this->coinsCollectedInLevel = 0;
	this->totalCoinsInLevel = 0;
	this->currentLevelFramecount = 0;
	this->currentLevelComplete = false;
	this->LoadCurrentLevel(activeObstacles);
}

unsigned int LevelHandler::GetCurrentLevelFramecount() const
{
	return this->currentLevelFramecount;
}

Vector2 LevelHandler::GetPlayerSpawnpoint() const
{
	return this->playerSpawnpoint;
}
