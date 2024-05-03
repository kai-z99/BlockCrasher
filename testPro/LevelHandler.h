#pragma once
#include <vector>
#include <raylib.h>

class Obstacle;
class ObstacleBuilder;

class LevelHandler
{
private:
	int currentLevel;
	bool currentLevelComplete;
	int coinsCollectedInLevel;
	int totalCoinsInLevel;
	bool levelFail;
	Vector2 playerSpawnpoint;
	ObstacleBuilder* obstacleBuilder;
	unsigned int currentLevelFramecount;
	
public:
	LevelHandler();
	void LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles);
	void UnloadCurrentLevel(std::vector<Obstacle*>& activeObstacles);
	void HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles);
	void SetLevel(int l);
	void FailCurrentLevel();
	void AddCoinCollected(int amount);
	unsigned int GetCurrentLevelFramecount() const;
	Vector2 GetPlayerSpawnpoint() const;


};