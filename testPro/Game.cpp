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
    this->player = new Player(50, 50);
    this->collisionManager = new CollisionManager();
    this->movementHandler = new PlayerMovementHandler();
    this->levelHandler = new LevelHandler();

    this->levelHandler->SetLevel(2);
    this->levelHandler->LoadCurrentLevel(this->activeObstacles);
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
		ob->Update(frame);
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
    }

    else
    {
        this->player->SetColor(WHITE);
    }
    
}

void Game::HandleLevel()
{
    this->levelHandler->HandleCurrentLevel();
}
