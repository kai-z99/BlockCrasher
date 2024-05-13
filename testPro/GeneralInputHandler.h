#pragma once
#include <vector>
#include <raylib.h>

class Player;
class LevelHandler;
class MenuHandler;
class Obstacle;
class Item;

class GeneralInputHandler
{
private:
	void HandleSelectLevelMenu(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);
	void HandleMainMenu(MenuHandler* menuHandler);
	
public:
	void HandleTryAgain(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);
	void HandleLevelComplete(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);
	void HandleBack(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	void HandleCurrentMenu(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);
	





	//void HandleAllInput(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);

};