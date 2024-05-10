#include "GeneralInputHandler.h"
#include "LevelHandler.h"
#include "Player.h"
#include "LevelStates.h"
#include "MenuHandler.h"
#include <iostream>

//check if space is pressed on try again screen, if so reset level
void GeneralInputHandler::HandleTryAgain(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
{
	if (IsKeyPressed(KEY_SPACE) && levelHandler->GetCurrentLevelState() == Fail)
	{
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());
	}
}


//check if space is pressed on level complete screen, if so go to next level
void GeneralInputHandler::HandleLevelComplete(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
{
	if (IsKeyPressed(KEY_SPACE) && levelHandler->GetCurrentLevelState() == Complete)
	{
		levelHandler->SetLevel(levelHandler->GetCurrentLevel() + 1);
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());

		levelHandler->SetLevelState(Active);

		//go to next level
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() + 1);

		//have to check if the level increment caused it to go to next page
		if (menuHandler->GetSelectedLevel() % menuHandler->levelsPerPage == 0)
		{
			menuHandler->SetCurrentPage(menuHandler->GetCurrentPage() + 1);
		}
	}
}


void GeneralInputHandler::HandleExitToMenu(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems)
{
	if (IsKeyPressed(KEY_BACKSPACE))
	{
		levelHandler->UnloadCurrentLevel(activeObstacles, activeItems);
		levelHandler->SetLevelState(Inactive);
	}
}
void GeneralInputHandler::HandleSelectLevelMenu(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
{
	//check is level is selected
	if (levelHandler->GetCurrentLevelState() == Inactive && (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)))
	{
		levelHandler->SetLevel(menuHandler->GetSelectedLevel());
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());

		levelHandler->SetLevelState(Active);
	}

	//check scroll down
	else if ((levelHandler->GetCurrentLevelState() == Inactive) && ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))) && ((menuHandler->GetSelectedLevel() % menuHandler->levelsPerPage) != 6)) // cannot go further than 6th level of each page 
	{
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() + 1);
	}

	//check scroll up
	else if (levelHandler->GetCurrentLevelState() == Inactive && (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && (menuHandler->GetSelectedLevel() % menuHandler->levelsPerPage != 0)  ) // cannot go further than firsr level of each page
	{
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() - 1);
	}

	//check menu right
	else if (levelHandler->GetCurrentLevelState() == Inactive && (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && (menuHandler->GetCurrentPage() != menuHandler->GetPageAmount())) //cant be on last page
	{
		menuHandler->SetCurrentPage(menuHandler->GetCurrentPage() + 1);
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() + menuHandler->levelsPerPage); // set selected level next pages corresponding level
	}

	//check menu left
	else if (levelHandler->GetCurrentLevelState() == Inactive && (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && (menuHandler->GetCurrentPage() != 1) && (menuHandler->GetCurrentPage() != 1)) // cant be on first page
	{
		menuHandler->SetCurrentPage(menuHandler->GetCurrentPage() - 1);
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() - menuHandler->levelsPerPage); // set selected level next pages corresponding level
	}



}
//
//void GeneralInputHandler::HandleAllInput(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
//{
//	this->HandleTryAgain(levelHandler, activeObstacles, activeItems, player);
//	this->HandleLevelComplete(levelHandler, activeObstacles, activeItems, player);
//}
