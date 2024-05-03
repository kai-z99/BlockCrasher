#include "Game.h"
#include "Player.h"
#include "CollisionManager.h"
#include "DynamicShapeObstacle.h"
#include "CircleObstacle.h"
#include "RectangleObstacle.h"
#include "ObstacleBuilder.h"
#include "Constants.h"


Game::Game()
{
    this->frameCount = 0;
	this->Init();
}

void Game::Run()
{
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



    // decontructor
    delete this->player;
    delete this->collisionManager;
    delete this->movementHandler;
    delete this->obstacleBuilder;

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
    this->obstacleBuilder = new ObstacleBuilder();

    /*this->obstacleBuilder->FlyingPentagon(300,300);
    this->obstacleBuilder->ClassicCircle(600, 600, 50, {1,1});
    this->obstacleBuilder->ClassicRectangle(500, 500, 60, 40, { 0,0 });*/
    this->obstacleBuilder->MasterSword((screenWidth / 2) - 50, (screenHeight / 2) - 200);
    this->obstacleBuilder->Insert(this->activeObstacles);
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
