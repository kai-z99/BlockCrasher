#include "Constants.h"
#include "LevelHandler.h"
#include "ObstacleBuilder.h"
#include "Obstacle.h"
#include "CoinItem.h"
#include "StarCoin.h"
#include "MenuHandler.h"
#include "DynamicShapeObstacle.h"

LevelHandler::LevelHandler()
{
	this->obstacleBuilder = new ObstacleBuilder();
	this->currentLevel = 0;
	this->totalCoinsInLevel = 1;
	this->coinsCollectedInLevel = 0;
	this->currentLevelFramecount = 0;
	this->currentLevelState = Inactive;
	this->playerSpawnpoint = { 0,0 };
	this->levelIsLoaded = false;
	this->currentLevelStarCoinCollected = false;
}

void LevelHandler::LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems)
{
	//used for level 6
	float rightMiddle; 
	float leftMiddle; 
	float pillarHeight = (float)(screenHeight / 2) + 1;  // one more than half screenheight to avoid seeing bottom of block at peak

	switch (this->currentLevel)
	{
	case 0:
		//---------
		//Obstacles
		//---------
		this->playerSpawnpoint = { 50,50 };														// 0
		this->obstacleBuilder->ClassicCircle(600, 600, 50, { 0,0 });							// 1
		this->obstacleBuilder->ClassicRectangle(500, 500, 60, 40, { 0,0 });						// 2


		//----------
		//Items
		//----------
		for (int i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 400));
		}
		this->totalCoinsInLevel = activeItems.size(); // temp

		activeItems.push_back(new StarCoin(screenWidth/2, 800));

		
		break;



	case 1:
		//---------
		//Obstacles
		//---------
		this->playerSpawnpoint = { 100,100 };
		this->obstacleBuilder->MasterSword((screenWidth / 2) - 50, (screenHeight / 2) - 200); // 0
		// Master Sword's Circle															  // 1

		//----------
		//Items
		//----------
		for (int i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i,800.0f));
		}

		for (int i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 300.0f));
		}

		activeItems.push_back(new StarCoin((screenWidth / 2) + 50, (screenHeight / 2) - 130));

		break;

	case 2:
		//---------
		//Obstacles
		//---------
		this->playerSpawnpoint = { 50,50 };													
		this->obstacleBuilder->FlyingPentagon(300,300);										// 0
		this->obstacleBuilder->ClassicCircle(600, 600, 50, {1,1});							// 1
		this->obstacleBuilder->ClassicRectangle(500, 500, 60, 40, { 0,0 });					// 2


		//----------
		//Items
		//----------
		for (int i = 200; i <= 1000; i += 50)
		{
			activeItems.push_back(new CoinItem(i, 400));
		}

		break;

	case 3:
		//---------
		//Obstacles
		//---------
		this->playerSpawnpoint = { 100,100 };												  
		this->obstacleBuilder->ClassicCircle(300, 600, 50, { -2,1 });						  // 0
		this->obstacleBuilder->ClassicCircle(600, 600, 50, { 1,-3 });						  // 1
		this->obstacleBuilder->ClassicCircle(600, 300, 50, { 4,1 });						  // 2
		this->obstacleBuilder->ClassicCircle(900, 100, 50, { -2,-4 });						  // 3
		this->obstacleBuilder->ClassicCircle(280, 600, 50, { 1,-3 });						  // 4
		this->obstacleBuilder->ClassicCircle(1000, 80, 50, { -1,8 });						  // 5

		//----------
		//Items
		//----------
		for (int i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 800));
		}

		for (int i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 300));
		}

		break;


	case 4:
		//---------
		//Obstacles
		//---------
		this->playerSpawnpoint = { 150, screenHeight/2 };

		this->obstacleBuilder->HollowBoxPiece(screenWidth/2 - 150*3, screenHeight/2 - 150*3, 0.01f, 0, 0, 3);
		this->obstacleBuilder->HollowBoxPiece(screenWidth/2 - 150*3, screenHeight/2 - 150*3, 0.01f, PI, 0, 3);

		this->obstacleBuilder->HollowBoxPiece(screenWidth / 2 - 150, screenHeight / 2 - 150, -0.01f, PI/2, 0.01, 1);
		this->obstacleBuilder->HollowBoxPiece(screenWidth / 2 - 150, screenHeight / 2 - 150, -0.01f, 3*PI/2, 0.01, 1);

		//----------
		//Items                           
		//----------
		
		for (int i = screenWidth/2 - 200; i <= screenWidth/2 + 200; i += 100) // bot row
		{
			activeItems.push_back(new CoinItem(i, screenHeight/2 + 200));
		}

		for (int i = screenWidth / 2 - 200; i <= screenWidth / 2 + 200; i += 100) //top row
		{
			activeItems.push_back(new CoinItem(i, screenHeight / 2 - 200));
		}

		for (int i = screenHeight / 2 - 100; i <= screenHeight / 2 + 100; i += 100) //left col
		{
			activeItems.push_back(new CoinItem(screenWidth / 2 - 200, i));
		}

		for (int i = screenHeight / 2 - 100; i <= screenHeight / 2 + 100; i += 100) //right col
		{
			activeItems.push_back(new CoinItem(screenWidth / 2 + 200, i));
		}

		activeItems.push_back(new StarCoin(screenWidth / 2, screenHeight / 2));

		break;

	case 5:
		this->playerSpawnpoint = { screenWidth / 2, screenHeight / 2 };

		//---------
		//Obstacles
		//---------

		this->obstacleBuilder->Wheel(0, (float)screenHeight /2 , 0.015, 0, 0, 2.6); //left
		this->obstacleBuilder->Wheel((float)screenWidth, (float)screenHeight / 2, 0.015, 0, 0, 2.6); // right
		this->obstacleBuilder->Wheel((float)screenWidth / 2, 0, 0.015, 0, 0, 2.6); // bot
		this->obstacleBuilder->Wheel((float)screenWidth / 2, screenHeight, 0.015, 0, 0, 2.6); // top

		//----------
		//Items                           
		//----------

		for (int i = 150; i <= 300; i += 50) // mid top
		{
			activeItems.push_back(new CoinItem(screenWidth / 2, i));
		}

		for (int i = 800; i <= 950; i += 50) // mid bot
		{
			activeItems.push_back(new CoinItem(screenWidth / 2, i));
		}

		for (int i = 200; i <= 900; i += 100) // left row
		{
			activeItems.push_back(new CoinItem(200, i));
		}

		for (int i = 200; i <= 900; i += 100) // right row
		{
			activeItems.push_back(new CoinItem(1720, i));
		}

		activeItems.push_back(new StarCoin(40, screenHeight/2 - 70));
		break;

	case 6:
		this->playerSpawnpoint = { screenWidth / 2, screenHeight / 2 };

		//---------
		//Obstacles
		//---------

		//bot crushers (bot start)

		this->obstacleBuilder->ClassicRectangle(0, screenHeight, 100, pillarHeight, { 0,-5 }); // left										//0
		this->obstacleBuilder->ClassicRectangle(screenWidth - 100, screenHeight, 100, pillarHeight, { 0,-5 }); // right					//1
		this->obstacleBuilder->ClassicRectangle(((float)screenWidth / 2) - 50, screenHeight, 100, pillarHeight, { 0,-5 }); // middle		//2


		//bot crushers (top start)

		leftMiddle = (((float)screenWidth / 2) + 50) / 2; // using the midpoint formula, where the length is x = screenWidth/2, p1 is x = 100, p2 is x = screenWdith/2 - 50
		this->obstacleBuilder->ClassicRectangle(leftMiddle - 50, (float)screenHeight / 2, 100, pillarHeight, { 0,5 }); // between left and middle //3
								
	
		rightMiddle = (((float)screenWidth * (3.0f/4.0f)) - 25); // using the midpoint formula, where the length is x = screenWidth, p1 is x = screenWidth/2 + 50, p2 is x = screenWidth - 100
		this->obstacleBuilder->ClassicRectangle(rightMiddle - 50, (float)screenHeight / 2, 100, pillarHeight, { 0,5 }); // between right and middle //4


		
		//top crushers (bot start)

		this->obstacleBuilder->ClassicRectangle(0, -pillarHeight, 100, pillarHeight, { 0,5 }); // left // 5
		this->obstacleBuilder->ClassicRectangle(screenWidth - 100, -pillarHeight, 100, pillarHeight, { 0,5 }); // right // 6
		this->obstacleBuilder->ClassicRectangle(((float)screenWidth / 2) - 50, -pillarHeight, 100, pillarHeight, { 0,5 }); // middle // 7
		
		//top crushers (top start)
		this->obstacleBuilder->ClassicRectangle(leftMiddle - 50, -1, 100, pillarHeight, { 0,-5 }); // between left and middle // 8
		this->obstacleBuilder->ClassicRectangle(rightMiddle - 50, -1, 100, pillarHeight, { 0,-5 }); // between right and middle // 9
		//               check def of pillarheight for explanation ^


		this->obstacleBuilder->NinjaStar(270.0f, 0.0f, 0.05f, 0.0f, 0.0f, { 0,5 }, 1.0f); // left star // 10, 11
		this->obstacleBuilder->NinjaStar(1185.0f, 0, 0.05f, 0.0f, 0.0f, { 0,5 }, 1.0f); // right middle star // 12, 13
		this->obstacleBuilder->NinjaStar(730.0f, screenHeight, 0.05f, 0.0f, 0.0f, { 0,-5 }, 1.0f); // left middle star // 14, 15
		this->obstacleBuilder->NinjaStar(screenWidth - 270.0f, screenHeight, 0.05f, 0.0f, 0.0f, { 0,-5 }, 1.0f); // right star // 16, 17
		
		


		
		for (int i = 200; i <= 900; i += 100) // left row
		{
			activeItems.push_back(new CoinItem(270.0f, i));
		}

		for (int i = 200; i <= 900; i += 100) // mid left row
		{
			activeItems.push_back(new CoinItem(730.0f, i));
		}

		for (int i = 200; i <= 900; i += 100) // mid right row
		{
			activeItems.push_back(new CoinItem(1185.0f, i));
		}

		for (int i = 200; i <= 900; i += 100) // mid right row
		{
			activeItems.push_back(new CoinItem(screenWidth - 270.0f, i));
		}

		activeItems.push_back(new StarCoin(rightMiddle, 100));
		

		break;

	default:
		break;

	}

	this->totalCoinsInLevel = activeItems.size() - 1; //-1 because it includes starCoin
	this->obstacleBuilder->Insert(activeObstacles);
	this->levelIsLoaded = true;
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

	this->levelIsLoaded = false;
}

void LevelHandler::HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* p, MenuHandler* menuHandler)
{	
	this->currentLevelFramecount += 1;

	//check win
	if (this->coinsCollectedInLevel >= this->totalCoinsInLevel)
	{
		this->currentLevelState = Complete;

		//mark compelted on menu screen
		menuHandler->SetLevelComplete(this->currentLevel);

		if (this->currentLevelStarCoinCollected)
		{
			menuHandler->SetLevelStarCoinCollected(this->currentLevel);
		}
	}

	//level specific handling
	switch (this->currentLevel)
	{
	case 0:
		//tutorial text
		DrawText("Collect all coins to complete the level!", 200, 320, 20, WHITE);
		DrawText("This is an optional Star Coin. Collect it before finishing!", screenWidth/2 - 280, screenHeight/2 + 300, 20, WHITE);
		DrawText("Careful! Don't get hit by obstacles!", 580, 500, 20, WHITE);
		break;

	case 3:
		//Bounce the ballz on the side of the screen
		for (int i = 0; i <= 5; i++)
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
	case 6:
		//MAKER THESE FOR LOOPS
		
		//check if bottom pillars should swtich velocity
		for (int i = 0; i <= 4; i++)
		{
			//middle of screen
			if (activeObstacles[i]->GetPosY() <= (float)screenHeight / 2)
			{
				activeObstacles[i]->SetVelocity(0, -activeObstacles[2]->GetVelocity().y);
			}

			//bottom of screen
			if (activeObstacles[i]->GetPosY() >= screenHeight)
			{
				activeObstacles[i]->SetVelocity(0, -activeObstacles[2]->GetVelocity().y);
			}

		}

		//top pillar check
		for (int i = 5; i <= 9; i++)
		{
			// middle of screen                   v check def of pillarheight for explanation
			if (activeObstacles[i]->GetPosY() >= -1)
			{
				activeObstacles[i]->SetVelocity(0, -activeObstacles[i]->GetVelocity().y);
			}
			
			//bottom of screen													v same here
			if (activeObstacles[i]->GetPosY() <=  ((float)(-screenHeight) / 2) + 1)
			{
				activeObstacles[i]->SetVelocity(0, -activeObstacles[i]->GetVelocity().y);
			}

		}


		// top start star checks
		for (int i = 10; i <= 13; i++)
		{
			if (activeObstacles[i]->GetPosY() >= screenHeight + 150) // + 150 since ninja star radius is 150
			{
				if (activeObstacles[i]->GetType() == DynamicShape)// check if its a star. If it is, we must use DynamicObstacleObject's SetPosY.
				{
					dynamic_cast<DynamicShapeObstacle*>(activeObstacles[i])->SetPosY(-150); 
				}

				else
				{
					activeObstacles[i]->SetPosY(-150); 
				}
				
			}
		}

		// bot start star checks
		for (int i = 14; i <= 17; i++)
		{
			if (activeObstacles[i]->GetPosY() <= -150) 
			{
				if (activeObstacles[i]->GetType() == DynamicShape) 
				{
					dynamic_cast<DynamicShapeObstacle*>(activeObstacles[i])->SetPosY(screenHeight + 150);
				}

				else
				{
					activeObstacles[i]->SetPosY(screenHeight + 150);
				}
			}
		}

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

void LevelHandler::SetLevelState(LevelState levelState)
{
	this->currentLevelState = levelState;
}

void LevelHandler::ResetCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems)
{
	this->UnloadCurrentLevel(activeObstacles, activeItems);
	this->coinsCollectedInLevel = 0;
	this->currentLevelStarCoinCollected = false;
	this->totalCoinsInLevel = 0;
	this->currentLevelFramecount = 0;
	this->currentLevelState = Active;
	this->LoadCurrentLevel(activeObstacles, activeItems);
}

unsigned int LevelHandler::GetCurrentLevelFramecount() const
{
	return this->currentLevelFramecount;
}

int LevelHandler::GetCurrentLevel() const
{
	return this->currentLevel;
}

int LevelHandler::GetCoinsCollected() const
{
	return this->coinsCollectedInLevel;
}

Vector2 LevelHandler::GetPlayerSpawnpoint() const
{
	return this->playerSpawnpoint;
}

LevelState LevelHandler::GetCurrentLevelState() const
{
	return this->currentLevelState;
}
