#pragma once
#include <vector>
#include <raylib.h>
#include "LevelStates.h"

class Obstacle;
class ObstacleBuilder;
class Player;
class Item;

class LevelHandler
{
private:
	int currentLevel;
	int coinsCollectedInLevel;
	int totalCoinsInLevel;
	Vector2 playerSpawnpoint;
	ObstacleBuilder* obstacleBuilder;
	unsigned int currentLevelFramecount;
	LevelState currentLevelState;
	
public:
	LevelHandler();

	void LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	void UnloadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	void HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* p);
	void ResetCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);

	void SetLevel(int l);
	void AddCoinsCollected(int amount);
	void SetLevelState(LevelState levelState);
	
	unsigned int GetCurrentLevelFramecount() const;
	int GetCurrentLevel() const;
	int GetCoinsCollected() const;
	Vector2 GetPlayerSpawnpoint() const;
	LevelState GetCurrentLevelState() const;
	
	bool levelIsLoaded;

};