#include "Game.h"
#include "Player.h"
#include "CollisionManager.h"
#include "DynamicShapeObstacle.h"
#include "CircleObstacle.h"
#include "RectangleObstacle.h"


Game::Game()
{
    this->frameCount = 0;
	this->Init();
}

void Game::Run()
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Raylib basic window");
    //ToggleFullscreen();
    DisableCursor();
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        frameCount++;
        this->HandleInput();
        this->HandleCollisions(); 
        this->Update(frameCount);
        this->Draw();
    }

    CloseWindow();
}

void Game::Init() // temp
{

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
