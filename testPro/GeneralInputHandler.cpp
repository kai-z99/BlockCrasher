#include "GeneralInputHandler.h"
#include "LevelHandler.h"
#include "Player.h"
#include "LevelStates.h"
#include "MenuHandler.h"
#include <iostream>

void GeneralInputHandler::HandleTryAgain(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
{
	if (IsKeyPressed(KEY_SPACE) && levelHandler->GetCurrentLevelState() == Fail)
	{
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());
	}
}

void GeneralInputHandler::HandleLevelComplete(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
{
	if (IsKeyPressed(KEY_SPACE) && levelHandler->GetCurrentLevelState() == Complete)
	{
		levelHandler->SetLevel(levelHandler->GetCurrentLevel() + 1);
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());

		levelHandler->SetLevelState(Active);

		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() + 1);
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
	if (levelHandler->GetCurrentLevelState() == Inactive && IsKeyPressed(KEY_SPACE))
	{
		levelHandler->SetLevel(menuHandler->GetSelectedLevel());
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());

		levelHandler->SetLevelState(Active);
	}

	else if (levelHandler->GetCurrentLevelState() == Inactive && IsKeyPressed(KEY_S) && menuHandler->GetSelectedLevel() != menuHandler->GetLevelsOnPage() - 1) // add or up arrow
	{
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() + 1);
	}

	else if (levelHandler->GetCurrentLevelState() == Inactive && IsKeyPressed(KEY_W) && menuHandler->GetSelectedLevel() != 0) // add or down arrow
	{
		menuHandler->SetSelectedLevel(menuHandler->GetSelectedLevel() - 1);
	}


}
//
//void GeneralInputHandler::HandleAllInput(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
//{
//	this->HandleTryAgain(levelHandler, activeObstacles, activeItems, player);
//	this->HandleLevelComplete(levelHandler, activeObstacles, activeItems, player);
//}
