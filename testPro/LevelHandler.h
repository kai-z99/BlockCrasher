#pragma once
#include <vector>
#include <raylib.h>
#include "LevelStates.h"

class Obstacle;
class ObstacleBuilder;
class Player;
class Item;
class MenuHandler;

class LevelHandler
{
private:
	int currentLevel;
	int coinsCollectedInLevel;
	int totalCoinsInLevel;
	
	Vector2 playerSpawnpoint;
	ObstacleBuilder* obstacleBuilder;

	unsigned int currentLevelFramecount;
	unsigned int currentLevelTime;
	unsigned int currentLevelTimeLimit;
	LevelState currentLevelState;
	
public:
	LevelHandler();

	void LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	void UnloadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	void HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* p, MenuHandler* menuHandler);
	void ResetCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);

	void SetLevel(int l);
	void AddCoinsCollected(int amount);
	void SetLevelState(LevelState levelState);
	void SetCurrentLevelTime(int time);
	
	unsigned int GetCurrentLevelFramecount() const;
	unsigned int GetCurrentLevelTime() const;
	unsigned int GetCurrentLevelTimeLimit() const;
	int GetCurrentLevel() const;
	int GetCoinsCollected() const;
	Vector2 GetPlayerSpawnpoint() const;
	LevelState GetCurrentLevelState() const;
	
	bool levelIsLoaded;
	bool currentLevelStarCoinCollected;

};