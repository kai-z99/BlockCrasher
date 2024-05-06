#pragma once
#include <vector>
#include <raylib.h>

class Player;
class LevelHandler;
class Obstacle;
class Item;

class GeneralInputHandler
{
private:
	

public:
	void HandleTryAgain(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);
	void HandleLevelComplete(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);




	//void HandleAllInput(LevelHandler* levelHandler, std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* player);

};