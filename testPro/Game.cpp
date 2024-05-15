#include "Game.h"
#include "Constants.h"
#include "Player.h"
#include "CollisionManager.h"
#include "PlayerMovementHandler.h"
#include "GeneralInputHandler.h"
#include "LevelHandler.h"
#include "Obstacle.h"
#include "CoinItem.h"
#include "LevelStates.h"
#include "MenuHandler.h"

Game::Game()
{
    this->frameCount = 0;
	this->Init();
}

void Game::Init() // temp
{
    this->collisionManager = new CollisionManager();
    this->movementHandler = new PlayerMovementHandler();
    this->inputHandler = new GeneralInputHandler();
    //this->menuHandler = new MenuHandler();
    this->levelHandler = new LevelHandler();
    this->player = new Player(this->levelHandler->GetPlayerSpawnpoint().x, this->levelHandler->GetPlayerSpawnpoint().y);

}

void Game::Run()
{
    InitWindow(screenWidth, screenHeight, "Welcome");
    //ToggleFullscreen();
    DisableCursor();
    SetTargetFPS(60);

    this->menuHandler = new MenuHandler(); // MeasureText only works when window is init.

    while (!WindowShouldClose()) {
        frameCount++;
        this->HandleInput();

        if (this->levelHandler->levelIsLoaded)
        {
            this->HandleCollisions();
        }
        
        this->Update(frameCount);
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



void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    //-------------------------
    //LEVEL DRAWING
    //-------------------------
    // 
    //draw player
    if (this->levelHandler->levelIsLoaded)
    {
        this->player->Draw();
        //this->player->DrawHitbox();

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
    }
    

    //--------------------
    // UI DRAWING
    //--------------------
    switch (this->levelHandler->GetCurrentLevelState())
    {
    case Complete:
    {
        int textWidth = MeasureText("LEVEL COMPLETE!", 50);
        DrawText("LEVEL COMPLETE!", (float)screenWidth / 2 - ((float)textWidth / 2), screenHeight / 2, 50, WHITE);

        textWidth = MeasureText("Press SPACE to go to next level.", 20);
        DrawText("Press SPACE to go to next level.", (float)screenWidth / 2 - ((float)textWidth / 2), (screenHeight / 2) + 60, 20, WHITE);
    }
    break;

    case Fail:
    {
        int textWidth = MeasureText("Press SPACE to try again.", 20);
        DrawText("Press SPACE to try again.", (float)screenWidth / 2 - ((float)textWidth / 2), (screenHeight / 2) + 60, 20, WHITE);

        if (this->levelHandler->GetCurrentLevelTime() == 0)
        {
            int textWidth = MeasureText("Times Up!", 40);
            DrawText("Times Up!", (float)screenWidth / 2 - ((float)textWidth / 2), (screenHeight / 2) + 20, 40, WHITE);
        }
    }
    break;

    default:
        break;
    }

    //draw menu
    this->menuHandler->DrawCurrentMenu(this->levelHandler);
    EndDrawing();

}

void Game::Update(unsigned int frame)
{
    switch (this->levelHandler->GetCurrentLevelState())
    {
    //unload level when level is compelete
    case Complete:
        if (this->levelHandler->levelIsLoaded)
        {
            this->levelHandler->UnloadCurrentLevel(this->activeObstacles, this->activeItems);
        }

        break;

    //change player color on fail
    case Fail:
        if (this->levelHandler->GetCurrentLevelTime() == 0)
        {
            this->player->SetColor(ORANGE);
        }

        else
        {
            this->player->SetColor(RED);
        }

        //this->levelHandler->HandleCurrentLevel(this->activeObstacles, this->activeItems, this->player, this->menuHandler);
        break;

    //update level when level is active
    case Active:
        this->player->SetColor(BLUE);

        // Update obstacle states
        for (Obstacle* ob : this->activeObstacles)
        {
            ob->Update(this->levelHandler->GetCurrentLevelFramecount());
        }

        // Update item states
        for (Item* it : this->activeItems)
        {
            it->Update(this->levelHandler->GetCurrentLevelFramecount(), this->player, this->levelHandler);
        }

        // handle the current level specifics
        this->levelHandler->HandleCurrentLevel(this->activeObstacles, this->activeItems, this->player, this->menuHandler);
        break;

    case Inactive:
        break;

    default:
        break;
    }
}


void Game::HandleInput()
{
    switch (this->levelHandler->GetCurrentLevelState())
    {
    case Active:
        this->movementHandler->HandlePlayerMovement(this->player);
        break;

    case Fail:
        this->inputHandler->HandleTryAgain(this->levelHandler, this->activeObstacles, this->activeItems, this->player);
        break;

    case Complete:
        this->inputHandler->HandleLevelComplete(this->menuHandler, this->levelHandler, this->activeObstacles, this->activeItems, this->player);
        break;

    case Inactive:
        this->inputHandler->HandleCurrentMenu(this->menuHandler, this->levelHandler, this->activeObstacles, this->activeItems, this->player);
        break;

    default:
        break;
    }

    this->inputHandler->HandleBack(this->menuHandler, this->levelHandler, this->activeObstacles, this->activeItems);
}


void Game::HandleCollisions()
{
    if (this->collisionManager->CheckCollisions(this->player, this->activeObstacles))
    {
        this->levelHandler->SetLevelState(Fail);
    }
}

