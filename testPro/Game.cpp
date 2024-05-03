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



    // decontructor
    delete this->player;
    delete this->collisionManager;
    delete this->movementHandler;

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


    std::vector<Vector2> v5;

    v5.push_back({ 700,700 });
    v5.push_back({ 700,900 });
    v5.push_back({ 900,1000 });
    v5.push_back({ 1000,900 });
    v5.push_back({ 900,700 });
    v5.push_back({ 700,700 });

    DynamicShapeObstacle* d = new DynamicShapeObstacle(800, 800, { 200, 700 }, v5, 0.01f, 0.01f, { 1,-1 });
    this->activeObstacles.push_back(d);
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
