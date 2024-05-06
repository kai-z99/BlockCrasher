#include "GeneralInputHandler.h"
#include "LevelHandler.h"
#include "Player.h"
#include "LevelStates.h"
#include <iostream>

void GeneralInputHandler::HandleTryAgain(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
{
	if (GetKeyPressed() == KEY_SPACE && levelHandler->GetCurrentLevelState() == Fail)
	{
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());
	}
}

void GeneralInputHandler::HandleLevelComplete(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
{
	if (GetKeyPressed() == KEY_SPACE && levelHandler->GetCurrentLevelState() == Complete)
	{
		levelHandler->SetLevel(levelHandler->GetCurrentLevel() + 1);
		levelHandler->ResetCurrentLevel(activeObstacles, activeItems);
		player->SetPosition(levelHandler->GetPlayerSpawnpoint());

		levelHandler->SetLevelState(Active);
	}
}
//
//void GeneralInputHandler::HandleAllInput(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player)
//{
//	this->HandleTryAgain(levelHandler, activeObstacles, activeItems, player);
//	this->HandleLevelComplete(levelHandler, activeObstacles, activeItems, player);
//}
