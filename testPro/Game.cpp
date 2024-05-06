#include "Game.h"
#include "Constants.h"
#include "Player.h"
#include "CollisionManager.h"
#include "GeneralInputHandler.h"
#include "LevelHandler.h"
#include "Obstacle.h"
#include "CoinItem.h"
#include "LevelStates.h"

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

        if (this->levelHandler->levelIsLoaded)
        {
            this->HandleLevel();
        }
        
        this->Draw();
    }

    // decontructor
    delete this->player;
    delete this->collisionManager;
    delete this->inputHandler;
    delete this->movementHandler;
    delete this->levelHandler;

    for (Obstacle* ob : this->activeObstacles)
    {
        delete ob;
    }

    for (Item* it : this->activeItems)
    {
        delete it;
    }

    CloseWindow();
}

void Game::Init() // temp
{
    this->collisionManager = new CollisionManager();
    this->movementHandler = new PlayerMovementHandler();
    this->inputHandler = new GeneralInputHandler();

    this->levelHandler = new LevelHandler();
    this->levelHandler->SetLevel(1);                                                //temp
    this->levelHandler->LoadCurrentLevel(this->activeObstacles, this->activeItems); //temp

    this->player = new Player(this->levelHandler->GetPlayerSpawnpoint().x, this->levelHandler->GetPlayerSpawnpoint().y);
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    //draw player
    if (this->levelHandler->levelIsLoaded)
    {
        this->player->Draw();
    }
    
    //draw current obstacles
	for (Obstacle* ob : this->activeObstacles)
	{
		ob->Draw();
	}

    //draw current items
    for (Item* it : this->activeItems)
    {
        if (!it->isCollected)
        {
            it->Draw();
        }
    }

    //draw menus if (levelHandler.levelisloaded == false)

    EndDrawing();
}

void Game::Update(unsigned int frame)
{
    //check level complete
    if (this->levelHandler->GetCurrentLevelState() == Complete)
    {
        if (this->levelHandler->levelIsLoaded)
        {
            this->levelHandler->UnloadCurrentLevel(this->activeObstacles, this->activeItems);
        }
        
        Vector2 textSize = MeasureTextEx(GetFontDefault(), "LEVEL COMPLETE!", 50, 0.0f);
        DrawText("LEVEL COMPLETE!", (float)screenWidth / 2 - (textSize.x / 2), screenHeight / 2, 50, WHITE);

        textSize = MeasureTextEx(GetFontDefault(), "Press SPACE to go to next level.", 20, 0.0f);
        DrawText("Press SPACE to go to next level.", (float)screenWidth / 2 - (textSize.x / 2), (screenHeight / 2) + 60, 20, WHITE);
        
    }

    else if (this->levelHandler->GetCurrentLevelState() == Fail)
    {
        this->player->SetColor(RED);
        Vector2 textSize = MeasureTextEx(GetFontDefault(), "Press SPACE to try again.", 20, 0.0f);
        DrawText("Press SPACE to try again.", (float)screenWidth / 2 - (textSize.x / 2), (screenHeight / 2) + 60, 20, WHITE);
    }

    else if (this->levelHandler->GetCurrentLevelState() == Active)
    {
        this->player->SetColor(BLUE);

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
}

void Game::HandleInput()
{
    if (this->levelHandler->GetCurrentLevelState() == Active)
    {
        this->movementHandler->HandlePlayerMovement(this->player);
    }
    
    else if (this->levelHandler->GetCurrentLevelState() == Fail)
    {
        this->inputHandler->HandleTryAgain(this->levelHandler, this->activeObstacles, this->activeItems, this->player);
    }

    else if (this->levelHandler->GetCurrentLevelState() == Complete)
    {
        this->inputHandler->HandleLevelComplete(this->levelHandler, this->activeObstacles, this->activeItems, this->player);
    }





    //this->inputHandler->HandleAllInput(this->levelHandler, this->activeObstacles, this->activeItems, this->player);
    
}

void Game::HandleCollisions()
{
    if (this->collisionManager->CheckCollisions(this->player, this->activeObstacles))
    {
        this->levelHandler->SetLevelState(Fail);
       /* this->levelHandler->ResetCurrentLevel(this->activeObstacles, this->activeItems);
        this->player->SetPosition({ this->levelHandler->GetPlayerSpawnpoint().x, this->levelHandler->GetPlayerSpawnpoint().y });*/
    }
}

void Game::HandleLevel()
{
    this->levelHandler->HandleCurrentLevel(this->activeObstacles, this->activeItems, this->player);
}

