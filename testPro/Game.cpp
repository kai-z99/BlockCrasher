#include "Game.h"
#include "Constants.h"
#include "Player.h"
#include "CollisionManager.h"
#include "LevelHandler.h"
#include "Obstacle.h"



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
    this->levelHandler->SetLevel(1);
    this->levelHandler->LoadCurrentLevel(this->activeObstacles);

    this->player = new Player(this->levelHandler->GetPlayerSpawnpoint().x, this->levelHandler->GetPlayerSpawnpoint().y);
    
   
    //this->levelHandler->UnloadCurrentLevel(this->activeObstacles);

}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    
    this->player->Draw();

	for (Obstacle* ob : this->activeObstacles)
	{
		ob->Draw();
	}



    EndDrawing();
}

void Game::Update(unsigned int frame)
{
	for (Obstacle* ob : this->activeObstacles)
	{
		ob->Update(this->levelHandler->GetCurrentLevelFramecount());
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
        this->levelHandler->FailCurrentLevel();
        this->player->SetPosition({ this->levelHandler->GetPlayerSpawnpoint().x, this->levelHandler->GetPlayerSpawnpoint().y });
    }

    else
    {
        this->player->SetColor(WHITE);
    }
    
}

void Game::HandleLevel()
{
    this->levelHandler->HandleCurrentLevel(this->activeObstacles);
}
