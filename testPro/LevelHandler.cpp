#include "Constants.h"
#include "LevelHandler.h"
#include "ObstacleBuilder.h"
#include "Obstacle.h"
#include "CoinItem.h"


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

void LevelHandler::LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems)
{
	switch (this->currentLevel)
	{
	case 1:
		//Obstacles
		this->playerSpawnpoint = { 100,100 };
		this->obstacleBuilder->MasterSword((screenWidth / 2) - 50, (screenHeight / 2) - 200); // 0
		// Master Sword's Circle															  // 1
		this->obstacleBuilder->ClassicCircle(300, 600, 50, { -2,1 });						  // 2 
		this->obstacleBuilder->ClassicCircle(600, 600, 50, { 1,-3 });						  // 3
		this->obstacleBuilder->ClassicCircle(600, 300, 50, { 4,1 });						  // 4

		//Items

		for (int i = 200; i <= 1000; i += 100)
		{
			activeItems.push_back(new CoinItem(i,400));
		}
		this->totalCoinsInLevel = activeItems.size(); // temp

		break;

	case 2:
		//Obstacles
		this->playerSpawnpoint = { 50,50 };													
		this->obstacleBuilder->FlyingPentagon(300,300);										// 0
		this->obstacleBuilder->ClassicCircle(600, 600, 50, {1,1});							// 1
		this->obstacleBuilder->ClassicRectangle(500, 500, 60, 40, { 0,0 });					// 2


		//items

		for (int i = 200; i <= 1000; i += 50)
		{
			activeItems.push_back(new CoinItem(i, 400));
		}
		this->totalCoinsInLevel = activeItems.size(); // temp

		break;

	default:
		break;

	}

	this->obstacleBuilder->Insert(activeObstacles);
}

void LevelHandler::UnloadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems)
{
	for (Obstacle* ob : activeObstacles)
	{
		delete ob;
	}

	for (Item* it : activeItems)
	{
		delete it;
	}

	activeObstacles.clear();
	activeItems.clear();
}

void LevelHandler::HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* p)
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

			if (activeObstacles[i]->GetPosX() + 50 > screenWidth || activeObstacles[i]->GetPosX() - 50 < 0)
			{
				activeObstacles[i]->SetVelocity(-activeObstacles[i]->GetVelocity().x, activeObstacles[i]->GetVelocity().y);
			}

			if (activeObstacles[i]->GetPosY() + 50 > screenHeight || activeObstacles[i]->GetPosY() - 50 < 0)
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

void LevelHandler::AddCoinsCollected(int amount)
{
	this->coinsCollectedInLevel += amount;
}

void LevelHandler::ResetCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems)
{
	this->UnloadCurrentLevel(activeObstacles, activeItems);
	this->coinsCollectedInLevel = 0;
	this->totalCoinsInLevel = 0;
	this->currentLevelFramecount = 0;
	this->currentLevelComplete = false;
	this->LoadCurrentLevel(activeObstacles, activeItems);
}

unsigned int LevelHandler::GetCurrentLevelFramecount() const
{
	return this->currentLevelFramecount;
}

int LevelHandler::GetCoinsCollected() const
{
	return this->coinsCollectedInLevel;
}

Vector2 LevelHandler::GetPlayerSpawnpoint() const
{
	return this->playerSpawnpoint;
}
