#include "Constants.h"
#include "LevelHandler.h"
#include "Player.h"
#include "ObstacleBuilder.h"
#include "Obstacle.h"
#include "CoinItem.h"
#include "StarCoin.h"
#include "MenuHandler.h"
#include "DynamicShapeObstacle.h"
#include "SoundManager.h"
#include "SoundEffect.h"


LevelHandler::LevelHandler()
{
	this->obstacleBuilder = new ObstacleBuilder();
	this->currentLevel = 0;
	this->totalCoinsInLevel = 0;
	this->coinsCollectedInLevel = 0;
	this->currentLevelFramecount = 0;
	this->currentLevelTime = 0;
	this->currentLevelTimeLimit = 30;
	this->currentLevelState = Inactive;
	this->playerSpawnpoint = { 0,0 };
	this->levelIsLoaded = false;
	this->currentLevelStarCoinCollected = false;
	this->currentTrackID = 0;
	this->currentLevelDisplayedYouAreHere = false;
}

void LevelHandler::LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems)
{
	switch (this->currentLevel)
	{
	case 0:

		this->playerSpawnpoint = { 50,400 };
		this->currentLevelTimeLimit = 60;
		this->currentTrackID = 2;

		//---------
		//Obstacles
		//---------
		
		this->obstacleBuilder->ClassicCircle(600, 600, 50, { 0,0 });							// 0
		this->obstacleBuilder->ClassicRectangle(500, 500, 60, 40, { 0,0 });						// 1

		//----------
		//Items
		//----------

		for (float i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 400));
		}

		activeItems.push_back(new StarCoin(screenWidth / 2, 800));

		break;



	case 1:

		this->playerSpawnpoint = { 100,100 };
		this->currentLevelTimeLimit = 20;
		this->currentTrackID = 12;

		//---------
		//Obstacles
		//---------
		
		this->obstacleBuilder->MasterSword((screenWidth / 2) - 50, (screenHeight / 2) - 200); // 0
		// Master Sword's Circle															  // 1

		//----------
		//Items
		//----------
		for (float i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 800.0f));
		}

		for (float i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 300.0f));
		}

		activeItems.push_back(new StarCoin((screenWidth / 2) + 50, (screenHeight / 2) - 130));

		break;

	case 2:

		this->playerSpawnpoint = { screenWidth / 2, screenHeight / 2 };
		this->currentLevelTimeLimit = 30;
		this->currentTrackID = 3;

		//---------
		//Obstacles
		//---------
		
		this->obstacleBuilder->RotatingBar(((float)screenWidth / 4) + 50, (float)screenHeight / 2, 0.02f, 0, 0, { 0,0 }, 6);						// 1 , 2
		this->obstacleBuilder->RotatingBar((3 * (float)screenWidth / 4), (float)screenHeight / 2, 0.08f, 0, 0.01f, { 0,0 }, 4);					// 3 , 4

		//----------
		//Items
		//----------

		//big bar
		for (float i = 190; i <= 390; i += 100)
		{
			activeItems.push_back(new CoinItem((float)screenWidth / 4 + 50, i));
		}

		for (float i = 690; i <= 890; i += 100)
		{
			activeItems.push_back(new CoinItem((float)screenWidth / 4 + 50, i));
		}


		for (float i = 180; i <= 900; i += 100)
		{
			activeItems.push_back(new CoinItem(i, (float)screenHeight / 2));
		}

		//small bar
		activeItems.push_back(new CoinItem(3 * (float)screenWidth / 4, (screenHeight / 2) + 180)); // top
		activeItems.push_back(new CoinItem(3 * (float)screenWidth / 4, (screenHeight / 2) - 180));	//bottom
		activeItems.push_back(new CoinItem((3 * (float)screenWidth / 4) - 180, screenHeight / 2));	//left
		activeItems.push_back(new CoinItem((3 * (float)screenWidth / 4) + 180, screenHeight / 2));	//left

		activeItems.push_back(new StarCoin(3 * (float)screenWidth / 4, 490));

		break;

	case 3:
		this->playerSpawnpoint = { 50, 50};
		this->currentLevelTimeLimit = 30;
		this->currentTrackID = 4;

		//---------
		//Obstacles
		//---------

		this->playerSpawnpoint = { 100,100 };
		this->currentLevelTimeLimit = 20;

		this->obstacleBuilder->ClassicCircle(300, 600, 50, { -2,1 });						  // 0
		this->obstacleBuilder->ClassicCircle(600, 600, 50, { 1,-3 });						  // 1
		this->obstacleBuilder->ClassicCircle(600, 300, 50, { 4,1 });						  // 2
		this->obstacleBuilder->ClassicCircle(900, 100, 50, { -2,-4 });						  // 3
		this->obstacleBuilder->ClassicCircle(280, 600, 50, { 1,-3 });						  // 4
		this->obstacleBuilder->ClassicCircle(1000, 80, 50, { -1,8 });						  // 5

		//----------
		//Items
		//----------

		for (float i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 800));
		}

		for (float i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 550));
		}


		for (float i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 300));
		}

		activeItems.push_back(new StarCoin(screenWidth - 50, screenHeight - 50));

		break;


	case 4: // Cubed
		this->playerSpawnpoint = { 150, screenHeight / 2 };
		this->currentLevelTimeLimit = 30;
		this->currentTrackID = 5;

		//---------
		//Obstacles
		//---------

		this->obstacleBuilder->HollowBoxPiece(screenWidth / 2 - 150 * 3, screenHeight / 2 - 150 * 3, 0.01f, 0, 0, 3);
		this->obstacleBuilder->HollowBoxPiece(screenWidth / 2 - 150 * 3, screenHeight / 2 - 150 * 3, 0.01f, PI, 0, 3);

		this->obstacleBuilder->HollowBoxPiece(screenWidth / 2 - 150, screenHeight / 2 - 150, -0.01f, PI / 2, 0.01f, 1);
		this->obstacleBuilder->HollowBoxPiece(screenWidth / 2 - 150, screenHeight / 2 - 150, -0.01f, 3 * PI / 2, 0.01f, 1);

		//----------
		//Items                           
		//----------

		for (float i = screenWidth / 2 - 200; i <= screenWidth / 2 + 200; i += 100) // bot row
		{
			activeItems.push_back(new CoinItem(i, screenHeight / 2 + 200));
		}

		for (float i = screenWidth / 2 - 200; i <= screenWidth / 2 + 200; i += 100) //top row
		{
			activeItems.push_back(new CoinItem(i, screenHeight / 2 - 200));
		}

		for (float i = screenHeight / 2 - 100; i <= screenHeight / 2 + 100; i += 100) //left col
		{
			activeItems.push_back(new CoinItem(screenWidth / 2 - 200, i));
		}

		for (float i = screenHeight / 2 - 100; i <= screenHeight / 2 + 100; i += 100) //right col
		{
			activeItems.push_back(new CoinItem(screenWidth / 2 + 200, i));
		}

		activeItems.push_back(new StarCoin(screenWidth / 2, screenHeight / 2));

		break;

	case 5: // Violent Tides
		this->playerSpawnpoint = { screenWidth / 2, screenHeight / 2 };
		this->currentLevelTimeLimit = 20;
		this->currentTrackID = 10;

		//---------
		//Obstacles
		//---------

		this->obstacleBuilder->Wheel(0, (float)screenHeight / 2, 0.015f, 0, 0, 2.6f); //left
		this->obstacleBuilder->Wheel((float)screenWidth, (float)screenHeight / 2, 0.015f, 0, 0, 2.6f); // right
		this->obstacleBuilder->Wheel((float)screenWidth / 2, 0, 0.015f, 0, 0, 2.6f); // bot
		this->obstacleBuilder->Wheel((float)screenWidth / 2, screenHeight, 0.015f, 0, 0, 2.6f); // top

		//----------
		//Items                           
		//----------

		for (float i = 150; i <= 300; i += 50) // mid top
		{
			activeItems.push_back(new CoinItem(screenWidth / 2, i));
		}

		for (float i = 800; i <= 950; i += 50) // mid bot
		{
			activeItems.push_back(new CoinItem(screenWidth / 2, i));
		}

		for (float i = 200; i <= 900; i += 100) // left row
		{
			activeItems.push_back(new CoinItem(200, i));
		}

		for (float i = 200; i <= 900; i += 100) // right row
		{
			activeItems.push_back(new CoinItem(1720, i));
		}

		activeItems.push_back(new StarCoin(40, screenHeight / 2 - 70));
		break;

	case 6: // High pressure
	{
		this->playerSpawnpoint = { screenWidth / 2, screenHeight / 2 };
		this->currentLevelTimeLimit = 20;
		this->currentTrackID = 9;

		float rightMiddle;
		float leftMiddle;
		float pillarHeight = (float)(screenHeight / 2) + 1;  // one more than half screenheight to avoid seeing bottom of block at peak

		//---------
		//Obstacles
		//---------

		//bot crushers (bot start)

		this->obstacleBuilder->ClassicRectangle(0, screenHeight, 100, pillarHeight, { 0,-5 }); // left									//0
		this->obstacleBuilder->ClassicRectangle(screenWidth - 100, screenHeight, 100, pillarHeight, { 0,-5 }); // right					//1
		this->obstacleBuilder->ClassicRectangle(((float)screenWidth / 2) - 50, screenHeight, 100, pillarHeight, { 0,-5 }); // middle	//2


		//bot crushers (top start)

		leftMiddle = (((float)screenWidth / 2) + 50) / 2; // using the midpoint formula, where the length is x = screenWidth/2, p1 is x = 100, p2 is x = screenWdith/2 - 50
		this->obstacleBuilder->ClassicRectangle(leftMiddle - 50, (float)screenHeight / 2, 100, pillarHeight, { 0,5 }); // between left and middle //3


		rightMiddle = (((float)screenWidth * (3.0f / 4.0f)) - 25); // using the midpoint formula, where the length is x = screenWidth, p1 is x = screenWidth/2 + 50, p2 is x = screenWidth - 100
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


		//----------
		//Items                           
		//----------

		for (float i = 200; i <= 900; i += 100) // left row
		{
			activeItems.push_back(new CoinItem(270.0f, i));
		}

		for (float i = 200; i <= 900; i += 100) // mid left row
		{
			activeItems.push_back(new CoinItem(730.0f, i));
		}

		for (float i = 200; i <= 900; i += 100) // mid right row
		{
			activeItems.push_back(new CoinItem(1185.0f, i));
		}

		for (float i = 200; i <= 900; i += 100) // mid right row
		{
			activeItems.push_back(new CoinItem(screenWidth - 270.0f, i));
		}

		activeItems.push_back(new StarCoin(rightMiddle, 100));

		break;

	}

	case 7: // Gridlocked

		this->playerSpawnpoint = { screenWidth / 2, screenHeight / 2 + 30 };
		this->currentLevelTimeLimit = 45;
		this->currentTrackID = 6;

		//---------
		//Obstacles
		//---------

		for (float i = -1000; i < 2920; i += 200) //x
		{
			for (float j = -1000; j < 2580; j += 200) //y
			{
				this->obstacleBuilder->GridPiece(i, j, 0.003f, 0, 0.005f, { 0,0 }, 1, { screenWidth / 2, screenHeight / 2 });
			}
		}

		//---------
		//Items
		//---------

		for (float i = (screenWidth/2) - 800; i <= (screenWidth / 2) + 800; i += 400) //x
		{
			for (float j = 280; j <= 900; j += 200) //y
			{
				activeItems.push_back(new CoinItem(i, j));
			}
		}

		activeItems.push_back(new StarCoin((screenWidth / 2) - 800, screenHeight - 40));
	
		break;

	case 8: // Happy trees

		this->playerSpawnpoint = { 200, screenHeight / 2 };
		this->currentLevelTimeLimit = 25;
		this->currentTrackID = 8;

		//---------
		//Obstacles
		//---------

		this->obstacleBuilder->Tree((float)screenWidth / 2, screenHeight, 0.01f, PI, 0.01f, { 0,0 }, 1.5);
		this->obstacleBuilder->Tree((float)screenWidth / 4, -100, 0.01f, 0, 0.01f, { 0,0 }, 1.3f);
		this->obstacleBuilder->Tree(3*(float)screenWidth / 4, -100, 0.01f, 0, 0.01f, { 0,0 }, 1.3f);


		//---------
		//Items
		//---------

		for (float i = (screenWidth / 2) - 800; i <= (screenWidth / 2) + 800; i += 200) // top row
		{
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) - 300));
			
		}

		for (float i = (screenWidth / 2) - 800; i < (screenWidth / 2); i += 200) //bot row left
		{
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) + 300));

		}

		for (float i = (screenWidth / 2) + 200; i <= (screenWidth / 2) + 800; i += 200) //bot row right
		{
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) + 300));

		}

		//mid coins
		for (float i = screenWidth / 4; i <= 3 * (screenWidth / 4); i += (screenWidth / 4))
		{
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) + 50));
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) - 50));
			activeItems.push_back(new CoinItem(i + 50, (screenHeight / 2)));
			activeItems.push_back(new CoinItem(i - 50, (screenHeight / 2)));
		}
		
		activeItems.push_back(new StarCoin(screenWidth/2, (screenHeight / 2) + 300));

		break;

	case 9:
		this->playerSpawnpoint = { 200,200 };
		this->currentLevelTimeLimit = 19;
		this->currentTrackID = 7;

		//---------
		//Obstacles
		//---------

		this->obstacleBuilder->Hook((screenWidth / 2) - 25, 1300, 0.002f, PI/2, 0.025f, { 0,0 }, 2); // 0 bot
		this->obstacleBuilder->Hook(screenWidth + 100, screenHeight / 2, 0.01f, PI, 0.025f, { 0,0 }, 2); // 1 top right
		this->obstacleBuilder->Hook(-150, screenHeight / 2, 0.005f, 0, 0.025f, { 0,0 }, 2);			//2 left
		this->obstacleBuilder->Hook(600,-100, 0.005f, -PI / 3, 0.025f, { 0,0 }, 2);				//3 top left

		//----------
		//Items
		//----------

		for (float i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 800.0f));
		}

		for (float i = 200; i <= 1700; i += 100)
		{
			activeItems.push_back(new CoinItem(i, 300.0f));
		}

		activeItems.push_back(new StarCoin(screenWidth - 50, (screenHeight / 2)));

		break;

	case 10:
		this->playerSpawnpoint = { 200, screenHeight / 2 };
		this->currentLevelTimeLimit = 32;
		this->currentTrackID = 11;

		//---------
		//Obstacles
		//---------

		// center vortex 4 pieces
		for (float angle = 0; angle < 2 * PI; angle += PI / 2) // 4 segments, so PI / 2 each time, exclude 2PI to prevent overlap.
		{
			this->obstacleBuilder->VortexPiece((screenWidth / 2) - 50, (screenHeight / 2) - 120, 0.02f, angle, 0.01f, { 0,0 }, 0.5f, { screenWidth / 2, screenHeight / 2 });
		}

		// layer 2 (from center) 3 pieces
		for (float angle = 0; angle <= 2 * PI; angle += 2 * PI / 3)  // 3 segemnts, so 2PI/3 each time
		{
			this->obstacleBuilder->VortexPiece((screenWidth / 2) - 100, (screenHeight / 2) - 250, -0.02f, angle, 0.005f, { 0,0 }, 1, { screenWidth / 2, screenHeight / 2 });
		}
		
		// layer 3 (from center) 5 pieces

		for (float angle = 0; angle <= 2 * PI; angle += 2 * PI / 5) // 5 segments, so 2pi/5 each time
		{
			this->obstacleBuilder->VortexPiece((screenWidth / 2) - 150, (screenHeight / 2) - 400, 0.02f, angle, -0.005f, { 0,0 }, 1.5, { screenWidth / 2, screenHeight / 2 });
		}

		// layer 4 (from center) 8 - 1 pieces

		for (int i = 0; i < 7; ++i) // 7 segments, spaced for 8
		{
			float angle = i * PI / 4; //					 +4 makes the gap spawn a lil closer on level start  v
			this->obstacleBuilder->VortexPiece((screenWidth / 2) - 200, (screenHeight / 2) - 600, -0.02f, angle + 4, 0.003f, { 0,0 }, 2, { screenWidth / 2, screenHeight / 2 });
		}

		this->obstacleBuilder->ClassicCircle(screenWidth / 2, screenHeight / 2, 10, {0,0});

		//----------
		//Items
		//----------

		for (float i = (screenWidth / 2) + 100; i <= 1920 - 400; i += 100) // right part of cross
		{
			activeItems.push_back(new CoinItem(i, screenHeight / 2));
		}

		for (float i = (screenWidth / 2) - 100; i >= 400; i -= 100) // left p.o.c
		{
			activeItems.push_back(new CoinItem(i, screenHeight / 2));
		}

		for (float i = (screenHeight / 2) + 100; i <= screenHeight; i += 100) // bot p.o.c
		{
			activeItems.push_back(new CoinItem(screenWidth / 2, i));
		}

		for (float i = (screenHeight / 2) - 100; i >= 100; i -= 100) // top p.o.c
		{
			activeItems.push_back(new CoinItem(screenWidth / 2, i));
		}

		activeItems.push_back(new StarCoin(screenWidth / 2, screenHeight / 2));

		//CROSS
		for (float i = 100; i <= 400; i += 100)
		{
			activeItems.push_back(new CoinItem((screenWidth / 4) + i, 70 + i)); // top left
			activeItems.push_back(new CoinItem((screenWidth / 4) + (screenWidth / 2) - i, 70 + i)); // top right
			activeItems.push_back(new CoinItem((screenWidth / 4) + i, screenHeight - 70 - i)); // bot left
			activeItems.push_back(new CoinItem((screenWidth / 4) + (screenWidth / 2) - i, screenHeight - 70 - i)); // bot right


		}

		break;

	case 11:
	{
		this->playerSpawnpoint = { screenWidth / 2, 100 };
		this->currentLevelTimeLimit = 28;
		this->currentTrackID = 13;


		//---------
		//Obstacles
		//---------
		float pillarHeight = (float)(screenHeight / 2) + 1;  // one more than half screenheight to avoid seeing bottom of block at peak

		//bot crushers (bot start)
		this->obstacleBuilder->ClassicRectangle(0, screenHeight, 500, pillarHeight, { 0,-13 }); // left									//0
		this->obstacleBuilder->ClassicRectangle(screenWidth - 500, screenHeight, 500, pillarHeight, { 0,-13 }); // right					//1

		//top crushers (bot start)
		this->obstacleBuilder->ClassicRectangle(0, -pillarHeight, 500, pillarHeight, { 0,13 }); // left // 5								//2
		this->obstacleBuilder->ClassicRectangle(screenWidth - 500, -pillarHeight, 500, pillarHeight, { 0,13 }); // right // 6			//3

		//stoppers
		
		// left
		this->obstacleBuilder->ClassicRectangle(0, (screenHeight / 2) - 50, 200, 100, { 0,0 }); 
		this->obstacleBuilder->ClassicRectangle(300, (screenHeight / 2) - 50, 200, 100, { 0,0 });
		//right
		this->obstacleBuilder->ClassicRectangle(screenWidth - 500, (screenHeight / 2) - 50, 400, 100, { 0,0 });


		//hammers
		this->obstacleBuilder->Hammer((screenWidth / 2), screenHeight - 430, 0.04f, 0, 0.02f, { 0,0 }, 1); //lower hammer
		this->obstacleBuilder->Hammer((screenWidth / 2), 210, -0.04f, 0, 0.02f, { 0,0 }, 1); // upper hammer

	
		//---------
		//ITEMS
		//---------
		// 
		// middle line of coins
		for (float i = 200; i <= 1000; i += 150) 
		{
			activeItems.push_back(new CoinItem(screenWidth / 2, i));
		}

		//in left stopper
		activeItems.push_back(new CoinItem(250, screenHeight / 2));

		//in right stopper
		activeItems.push_back(new CoinItem(screenWidth - 50, screenHeight / 2));

		// coins next to stopper (left) close
		for (float i = 50; i <= 500; i += 100)
		{
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) - 100));
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) + 100));
		}

		// coins next to stopper (left) far
		for (float i = 150; i <= 350; i += 100)
		{
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) - 200));
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) + 200));
		}

		// coins next to stopper (right) far
		for (float i = screenWidth - 400; i < screenWidth - 100; i += 100)
		{
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) - 200));
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) + 200));
		}

		// coins next to stopper (right) close
		for (float i = screenWidth - 350; i <= screenWidth - 250; i += 100)
		{
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) - 100));
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) - 100));
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) + 100));
			activeItems.push_back(new CoinItem(i, (screenHeight / 2) + 100));
		}

		activeItems.push_back(new StarCoin(screenWidth - 50, 160));

		break;
	}

	case 12:
		this->playerSpawnpoint = { screenWidth / 2 - 85, screenHeight / 2 - 100 };
		this->currentLevelTimeLimit = 19;
		this->currentTrackID = 14;

		//---------
		//Obstacles
		//---------

		//small raindrops
		for (float i = 0; i <= screenWidth; i += 400)
		{
			for (float j = 300; j <= screenHeight; j += 400)
			{
				this->obstacleBuilder->RainDrop(i, j, 0, 0, 0, { -3,3 }, 0.6f);
			}
			
		}

		//large raindrops
		for (float i = 150; i <= screenWidth; i += 400)
		{
			for (float j = 150; j <= screenHeight; j += 400)
			{
				this->obstacleBuilder->RainDrop(i, j, 0, 0, 0, { -3,3 }, 1.0f);
			}
			
		}

		//ninja stars
		this->obstacleBuilder->NinjaStar((screenWidth / 2), (screenHeight / 2) - 200, 0.1f, 0.0f, 0.0f, { -1,1 }, 0.3f);
		this->obstacleBuilder->NinjaStar((screenWidth / 2) - 90, (screenHeight / 2) + 200, 0.1f, 0.0f, 0.0f, { -1,1 }, 0.3f);
		this->obstacleBuilder->NinjaStar((screenWidth / 2) + 580, (screenHeight / 2), 0.1f, 0.0f, 0.0f, { -1,1 }, 0.3f);
		this->obstacleBuilder->NinjaStar((screenWidth / 2) + 580, (screenHeight / 2) - 450, 0.1f, 0.0f, 0.0f, { -1,1 }, 0.3f);
		this->obstacleBuilder->NinjaStar((screenWidth / 2) + 200, (screenHeight / 2) + 400, 0.1f, 0.0f, 0.0f, { -1,1 }, 0.3f);
		this->obstacleBuilder->NinjaStar((screenWidth / 2) - 600, (screenHeight / 2), 0.1f, 0.0f, 0.0f, { -1,1 }, 0.3f);
		this->obstacleBuilder->NinjaStar((screenWidth / 2) - 640, (screenHeight / 2) - 400, 0.1f, 0.0f, 0.0f, { -1,1 }, 0.3f);
		this->obstacleBuilder->NinjaStar((screenWidth / 2) - 640, (screenHeight / 2) + 400, 0.1f, 0.0f, 0.0f, { -1,1 }, 0.3f);
		this->obstacleBuilder->NinjaStar((screenWidth) - 75, (screenHeight) - 100, 0.1f, 0.0f, 0.0f, { -1,1 }, 0.3f);


		//this->obstacleBuilder->RotatingBar(screenWidth / 2, screenHeight / 2, -0.005, 0, 0, { 0,0 }, 18);
		
		//----------
		//Items
		//----------

		for (float i = 250; i <= screenWidth - 200; i += 250)
		{
			for (float j = 200; j <= screenHeight; j += 250)
			activeItems.push_back(new CoinItem(i, j));
		}



		activeItems.push_back(new StarCoin(screenWidth - 100, (screenHeight / 2) + 20));

		break;

	case 13:
		this->playerSpawnpoint = { screenWidth / 2, screenHeight / 2 - 250};
		this->currentLevelTimeLimit = 28; //28
		this->currentTrackID = 15;

		//---------
		//Obstacles
		//---------

		this->obstacleBuilder->BattleShip(screenWidth / 2, screenHeight / 2 + 270, 0.005f, PI, 0.015f, { 0,0 }, 1);

		this->obstacleBuilder->Anchor(screenWidth / 2, 0, -0.03f, PI, 0.03f, { 1.5 * -3,1.5 * 1 }, 0.75);
		this->obstacleBuilder->Anchor(300, 200, 0.03f, PI, 0.03f, { 1.5 * -3,1.5 * 2 }, 0.75);
		this->obstacleBuilder->Anchor(screenWidth - 300, 200, 0.03f, PI, 0.03f, { 1.5 * -3,1.5 * -1 }, 0.75);

		//----------
		//Items
		//----------
		// 
		//left side bot
		for (float i = screenWidth / 2 - 100; i >= 100; i -= 100)
		{
			activeItems.push_back(new CoinItem(i, screenHeight - 150));
		}

		//right side bot
		for (float i = screenWidth / 2 + 100; i <= screenWidth - 100; i += 100)
		{
			activeItems.push_back(new CoinItem(i, screenHeight - 150));
		}

		//bot middle to top
		for (float i = screenHeight - 250; i >= 400; i -= 100)
		{
			activeItems.push_back(new CoinItem(screenWidth / 2, i));
		}

		//top coin clusters
		for (float i = screenWidth / 4; i <= 3 * (screenWidth / 4); i += (screenWidth / 4))
		{
			activeItems.push_back(new CoinItem(i, (150) + 50));
			activeItems.push_back(new CoinItem(i, (150) - 50));
			activeItems.push_back(new CoinItem(i + 50, (150)));
			activeItems.push_back(new CoinItem(i - 50, (150)));
		}

		for (float i = screenWidth / 3; i <= 2 * (screenWidth / 3); i += (screenWidth / 3))
		{
			//activeItems.push_back(new CoinItem(i, (screenHeight / 2 + 100) + 40));
			//activeItems.push_back(new CoinItem(i, (screenHeight / 2 + 100) - 40));
			//activeItems.push_back(new CoinItem(i + 40, (screenHeight / 2 + 100)));
			//activeItems.push_back(new CoinItem(i - 40, (screenHeight / 2 + 100)));
			activeItems.push_back(new CoinItem(i - 100, (screenHeight / 2 + 100) - 100));
			activeItems.push_back(new CoinItem(i + 100, (screenHeight / 2 + 100) + 100));
			activeItems.push_back(new CoinItem(i - 100, (screenHeight / 2 + 100) + 100));
			activeItems.push_back(new CoinItem(i + 100, (screenHeight / 2 + 100) - 100));
		}

		activeItems.push_back(new StarCoin(screenWidth / 2, screenHeight - 150));
		break;

	default:

		break;

	}

	this->currentLevelTime = this->currentLevelTimeLimit;
	this->totalCoinsInLevel = (int)activeItems.size() - 1; //-1 because it includes starCoin
	this->obstacleBuilder->Insert(activeObstacles);
	this->levelIsLoaded = true;
	this->currentLevelDisplayedYouAreHere = false; // this draws the circle after every death

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

void LevelHandler::HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* p, MenuHandler* menuHandler, SoundManager* soundManager)
{	
	this->currentLevelFramecount += 1;

	//decrement timer every second (if not on fail screen)
	if (this->currentLevelFramecount % 60 == 0 && this->currentLevelTime != 0 && this->currentLevelState == Active)
	{
		this->currentLevelTime--;
	}

	//check win
	if (this->coinsCollectedInLevel >= this->totalCoinsInLevel && this->currentLevelState != Complete)
	{
		this->currentLevelState = Complete;

		//stop the music
		soundManager->PlaySoundFile(LevelWin_Sound);
		soundManager->StopMusic();

		//mark compelted on menu screen
		menuHandler->SetLevelComplete(this->currentLevel);

		if (this->currentLevelStarCoinCollected)
		{
			menuHandler->SetLevelStarCoinCollected(this->currentLevel);
		}
		
	}

	//check timer loss
	else if (this->currentLevelTime == 0 && this->currentLevelState != Fail)
	{
		this->currentLevelState = Fail;
		soundManager->PlaySoundFile(TimesUp_Sound);
	}

	// if the player hasnt moved, draw the you are here circle.
	if (p->GetPosX() == this->playerSpawnpoint.x && p->GetPosY() == this->playerSpawnpoint.y && this->currentLevelDisplayedYouAreHere == false)
	{
		p->DrawYouAreHere(this->currentLevelFramecount);
	}

	else
	{
		this->currentLevelDisplayedYouAreHere = true;
	}

	//level specific handling
	switch (this->currentLevel)
	{
	case 0:
		//tutorial text
		DrawText("i.) Move with WASD or arrow keys!", 40, (screenHeight / 2) - 100, 20, WHITE);
		DrawText("ii.) Collect all coins to complete the level!", 200, 320, 20, WHITE);
		DrawText("iv.) This is the timer. Don't let it tick to 0!", (screenWidth / 2) - 210, 70, 20, WHITE);
		DrawText("v.) This is an optional Star Coin. Collect it before finishing!", screenWidth/2 - 280, screenHeight/2 + 300, 20, WHITE);
		DrawText("iii.) Careful! Don't get hit by obstacles!", 580, 500, 20, WHITE);
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
			
			//top of screen														v same here
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


	case 7:


		for (Obstacle* ob : activeObstacles)
		{
			ob->SetPosY(ob->GetPosY() + (1 * sinf(this->currentLevelFramecount * 0.01f)));
			ob->SetPosX(ob->GetPosX() + (1 * cosf(this->currentLevelFramecount * 0.01f)));
		}
		break;
																				//    movement length/speed                          movement frequency
		//case x: lateral movement of grid: activeitems[i]->SetVelocity(activeItems[i].GetVelocity().x + (someConstant1 * sin(this->currentLevelFrameCount * someConstant2)), activeItems[i].GetVelocity().y )
		//also, if you do the same with y-velocity and cosine, you get circular movement. at cos(0), should be maximum y velocity, at sin(0), you start with 0 x velocity.


	case 9:
		//hook movements

		activeObstacles[0]->SetPosX(activeObstacles[0]->GetPosX() + (3.0f * cosf(this->currentLevelFramecount * 0.01f)));

		activeObstacles[1]->SetPosX(activeObstacles[1]->GetPosX() + (1.5f * cosf(this->currentLevelFramecount * 0.02f)));
		activeObstacles[1]->SetPosY(activeObstacles[1]->GetPosY() + (1.5f * cosf(this->currentLevelFramecount * 0.02f)));

		activeObstacles[2]->SetPosY(activeObstacles[2]->GetPosY() + (2.0f * cosf(this->currentLevelFramecount * 0.015f)));

		activeObstacles[3]->SetPosX(activeObstacles[3]->GetPosX() + (2.5f * cosf(this->currentLevelFramecount * 0.02f)));
		
		break;

	case 10:

		//smooth right left right... movement
		for (Obstacle* ob : activeObstacles)
		{
			ob->SetPosX(ob->GetPosX() + (1 * cosf(this->currentLevelFramecount * 0.01f)));
		}
		break;

	case 11:

		//check if bottom pillars should swtich velocity
		for (int i = 0; i <= 1; i++)
		{
			//middle of screen + blockers
			if (activeObstacles[i]->GetPosY() <= ((float)screenHeight / 2) + 50)
			{
				activeObstacles[i]->SetVelocity(0, 5);
			}

			//bottom of screen
			if (activeObstacles[i]->GetPosY() >= screenHeight)
			{
				activeObstacles[i]->SetVelocity(0, -13);
			}

		}

		//top pillar check
		for (int i = 2; i <= 3; i++)
		{
			// middle of screen + blockers       
			if (activeObstacles[i]->GetPosY() >= -50)
			{
				activeObstacles[i]->SetVelocity(0, -5);
			}

			//top of screen														v same here
			if (activeObstacles[i]->GetPosY() <= ((float)(-screenHeight) / 2) + 1)
			{
				activeObstacles[i]->SetVelocity(0, 13);
			}

		}
		break;

	case 12:
		for (Obstacle* ob : activeObstacles)
		{
			float dropSize = 100;
			if (ob->GetPosX() <= -dropSize) // obj hits left side of screen
			{
				ob->SetPosX(ob->GetPosY() - dropSize);
				ob->SetPosY(0);
				
			}

			if (ob->GetPosY() >= screenHeight + dropSize) // obj hits bottom of the screen
			{
				float x0 = ob->GetPosX() + dropSize;
				float y0 = ob->GetPosY() - dropSize;

				float x1 = x0 + screenHeight;
				float y1 = 0;

				if (x1 > screenWidth)
				{
					x1 = screenWidth;
					y1 = x0 - (screenWidth - screenHeight);
				}

				ob->SetPosY(y1);
				ob->SetPosX(x1);  

			}


		}
		break;

	case 13:
			

			//ship check
			activeObstacles[0]->SetPosX(activeObstacles[0]->GetPosX() + (2 * cosf(this->currentLevelFramecount * 0.01f)));
			activeObstacles[0]->SetPosY(activeObstacles[0]->GetPosY() + (1 * sinf(this->currentLevelFramecount * 0.01f)));
			



			// Anchor check
			for (int i = 1; i <= 5; i += 2)
			{
				if (activeObstacles[i]->GetPosX() < -230) // check if they hit left side of screen
				{
					dynamic_cast<DynamicShapeObstacle*>(activeObstacles[i])->SetPosX(screenWidth + 230);
					dynamic_cast<DynamicShapeObstacle*>(activeObstacles[i])->SetPosY(1.7 * 240);
					activeObstacles[i]->SetVelocity(1.5 * -3, 1.5 * -1);
				}

				else if (activeObstacles[i]->GetPosX() < screenWidth / 2) // check if they hit middle of screen
				{
					activeObstacles[i]->SetVelocity(1.5 * -3, 1.5 * 1);
				}
			}


			//anchor circle check
			for (int i = 2; i <= 6; i += 2)
			{
				if (activeObstacles[i]->GetPosX() < -230)  // check if they hit left side of screen
				{
					activeObstacles[i]->SetPosX(screenWidth + 230);
					activeObstacles[i]->SetPosY(1.7 * 240);
					activeObstacles[i]->SetVelocity(1.5 * -3, 1.5 * -1);
				}

				if (activeObstacles[i]->GetPosX() < screenWidth / 2)  // check if they hit middle of screen
				{
					activeObstacles[i]->SetVelocity(1.5 * -3, 1.5 * 1);
				}
			}


			



		break;


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

void LevelHandler::SetCurrentLevelTime(int time)
{
	this->currentLevelTime = time;
}

void LevelHandler::ResetCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems)
{
	this->UnloadCurrentLevel(activeObstacles, activeItems);

	this->coinsCollectedInLevel = 0;
	this->currentLevelStarCoinCollected = false;
	this->totalCoinsInLevel = 0;
	this->currentLevelFramecount = 0;
	this->currentLevelState = Active;
	this->currentLevelTime = this->currentLevelTimeLimit;

	this->LoadCurrentLevel(activeObstacles, activeItems);
}

unsigned int LevelHandler::GetCurrentLevelFramecount() const
{
	return this->currentLevelFramecount;
}

unsigned int LevelHandler::GetCurrentLevelTime() const
{
	return this->currentLevelTime;
}

unsigned int LevelHandler::GetCurrentLevelTimeLimit() const
{
	return this->currentLevelTimeLimit;
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

int LevelHandler::GetCurrentTrackID() const
{
	return this->currentTrackID;
}
