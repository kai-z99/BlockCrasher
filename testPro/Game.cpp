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
    ToggleFullscreen();
    DisableCursor();
    SetTargetFPS(60);

    this->menuHandler = new MenuHandler(); // MeasureText only works when window is init.

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
    //UI DRAWING
    //-----------------------
    if (this->levelHandler->GetCurrentLevelState() == Complete) //credit last level
    {
        int textWidth = MeasureText("LEVEL COMPLETE!", 50);
        DrawText("LEVEL COMPLETE!", (float)screenWidth / 2 - ((float)textWidth / 2), screenHeight / 2, 50, WHITE);

        textWidth = MeasureText("Press SPACE to go to next level.", 20);
        DrawText("Press SPACE to go to next level.", (float)screenWidth / 2 - (textWidth / 2), (screenHeight / 2) + 60, 20, WHITE);

    }

    else if (this->levelHandler->GetCurrentLevelState() == Fail)
    {
        int textWidth = MeasureText("Press SPACE to try again.", 20);
        DrawText("Press SPACE to try again.", (float)screenWidth / 2 - ((float)textWidth / 2), (screenHeight / 2) + 60, 20, WHITE);
    }

    else if (this->levelHandler->GetCurrentLevelState() == Active)
    {
        //draw timer, coins collected/c, esc to exit
    }

   
    //draw menus if (levelHandler.levelisloaded == false)
    if (this->levelHandler->GetCurrentLevelState() == Inactive && this->levelHandler->levelIsLoaded == false)
    {
        this->menuHandler->DrawLevelSelectMenu(); // temp page 1
    }

    EndDrawing();
}

void Game::Update(unsigned int frame)
{
    //check level complete, unload level if so
    if (this->levelHandler->GetCurrentLevelState() == Complete)
    {
        if (this->levelHandler->levelIsLoaded)
        {
            this->levelHandler->UnloadCurrentLevel(this->activeObstacles, this->activeItems);
        }
    }

    else if (this->levelHandler->GetCurrentLevelState() == Fail)
    {
        this->player->SetColor(RED);
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

    //else if (this->levelHandler->GetCurrentLevelState() == Inactive)
    //{
    //    
    //}
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
        this->inputHandler->HandleLevelComplete(this->menuHandler, this->levelHandler, this->activeObstacles, this->activeItems, this->player);
    }

    this->inputHandler->HandleExitToMenu(this->levelHandler, this->activeObstacles, this->activeItems);

    if (this->levelHandler->GetCurrentLevelState() == Inactive)
    {
        this->inputHandler->HandleSelectLevelMenu(this->menuHandler, this->levelHandler, this->activeObstacles, this->activeItems, this->player);
    }



}

void Game::HandleCollisions()
{
    if (this->collisionManager->CheckCollisions(this->player, this->activeObstacles))
    {
        this->levelHandler->SetLevelState(Fail);
    }
}

void Game::HandleLevel()
{
    this->levelHandler->HandleCurrentLevel(this->activeObstacles, this->activeItems, this->player, this->menuHandler);
}

