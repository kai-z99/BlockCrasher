#include "Game.h"
#include "Constants.h"
#include "Player.h"
#include "CollisionManager.h"
#include "LevelHandler.h"
#include "Obstacle.h"
#include "CoinItem.h"


Game::Game()
{
    this->frameCount = 0;
	this->Init();
}

void Game::Run()
{
    InitWindow(screenWidth, screenHeight, "Raylib basic window");
    ToggleFullscreen();
    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        frameCount++;
        this->HandleInput();
        this->HandleCollisions(); 
        this->Update(frameCount);
        this->HandleLevel();
        this->Draw();
    }

    // decontructor
    delete this->player;
    delete this->collisionManager;
    delete this->movementHandler;
    //delete this->obstacleBuilder;

    for (Obstacle* ob : this->activeObstacles)
    {
        delete ob;
    }

    CloseWindow();
}

void Game::Init() // temp
{
    this->collisionManager = new CollisionManager();
    this->movementHandler = new PlayerMovementHandler();

    this->levelHandler = new LevelHandler();
    this->levelHandler->SetLevel(1);                             //temp
    this->levelHandler->LoadCurrentLevel(this->activeObstacles); //temp

    this->player = new Player(this->levelHandler->GetPlayerSpawnpoint().x, this->levelHandler->GetPlayerSpawnpoint().y);

    //this->activeItems.push_back(new CoinItem(500,500));
    //this->activeItems.push_back(new CoinItem(700, 500));

}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    //DrawRingLines({100,100}, 3,11, 0, 320, 6, YELLOW);
    /*DrawRingLines({ 100,120 }, 3, 11, 90, 320+90, 6, YELLOW);
    DrawRingLines({ 100,140 }, 3, 11, 180, 320+180, 6, YELLOW);
    DrawRingLines({ 100,160 }, 3, 11, 270, 320+270, 6, YELLOW);*/
    //draw player
    this->player->Draw();


    //draw current obstacles
	for (Obstacle* ob : this->activeObstacles)
	{
		ob->Draw();
	}

    for (Item* it : this->activeItems)
    {
        if (!it->isCollected)
        {
            it->Draw();
        }
    }

    EndDrawing();
}

void Game::Update(unsigned int frame)
{
    //update obstacle states
	for (Obstacle* ob : this->activeObstacles)
	{
		ob->Update(this->levelHandler->GetCurrentLevelFramecount());
	}


    //update item states
    for (Item* it : this->activeItems)
    {
        it->Update(this->levelHandler->GetCurrentLevelFramecount(), this->player, this->levelHandler);
    }

}

void Game::HandleInput()
{
    this->movementHandler->HandlePlayerMovement(this->player);
}

void Game::HandleCollisions()
{
    if (this->collisionManager->CheckCollisions(this->player, this->activeObstacles))
    {
        this->player->SetColor(RED);
        this->levelHandler->ResetCurrentLevel(this->activeObstacles);
        this->player->SetPosition({ this->levelHandler->GetPlayerSpawnpoint().x, this->levelHandler->GetPlayerSpawnpoint().y });
    }

    else
    {
        this->player->SetColor(WHITE);
    }
    
}

void Game::HandleLevel()
{
    this->levelHandler->HandleCurrentLevel(this->activeObstacles, this->player);
}
