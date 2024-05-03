#pragma once
#include <vector>
#include <raylib.h>

class Obstacle;
class ObstacleBuilder;
class Player;

class LevelHandler
{
private:
	int currentLevel;
	bool currentLevelComplete;
	int coinsCollectedInLevel;
	int totalCoinsInLevel;
	Vector2 playerSpawnpoint;
	ObstacleBuilder* obstacleBuilder;
	unsigned int currentLevelFramecount;
	
public:
	LevelHandler();
	void LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles);
	void UnloadCurrentLevel(std::vector<Obstacle*>& activeObstacles);
	void HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles, Player* p);
	void SetLevel(int l);
	void AddCoinsCollected(int amount);
	void ResetCurrentLevel(std::vector<Obstacle*>& activeObstacles);
	unsigned int GetCurrentLevelFramecount() const;
	int GetCoinsCollected() const;
	Vector2 GetPlayerSpawnpoint() const;


};