#pragma once
#include <vector>
#include <raylib.h>

class Player;
class LevelHandler;
class MenuHandler;
class Obstacle;
class Item;
class SoundManager;

class GeneralInputHandler
{
private:
	void HandleSelectLevelMenu(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player, SoundManager* soundManager);
	void HandleMainMenu(MenuHandler* menuHandler, SoundManager* soundManager);
	
public:
	void HandleTryAgain(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);
	void HandleLevelComplete(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player, SoundManager* soundManager);
	void HandleBack(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, SoundManager* soundManager);
	void HandleCurrentMenu(MenuHandler* menuHandler, LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player, SoundManager* soundManager);
	





	//void HandleAllInput(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);

};