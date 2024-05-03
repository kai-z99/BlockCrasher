#pragma once
#include <vector>
#include <raylib.h>

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
	
public:
	LevelHandler();
	void LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	void UnloadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	void HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* p);
	void SetLevel(int l);
	void AddCoinsCollected(int amount);
	void ResetCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	unsigned int GetCurrentLevelFramecount() const;
	int GetCoinsCollected() const;
	bool currentLevelComplete;
	Vector2 GetPlayerSpawnpoint() const;


};