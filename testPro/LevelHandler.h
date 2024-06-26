#pragma once
#include <vector>
#include <raylib.h>
#include "LevelStates.h"

class Obstacle;
class ObstacleBuilder;
class Player;
class Item;
class MenuHandler;
class SoundManager;

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
	int currentTrackID;
	bool currentLevelDisplayedYouAreHere;

public:
	LevelHandler();

	void LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	void UnloadCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems);
	void HandleCurrentLevel(std::vector<Obstacle*>& activeObstacles, std::vector<Item*>& activeItems, Player* p, MenuHandler* menuHandler, SoundManager* soundManager);
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
	int GetCurrentTrackID() const;
	
	bool levelIsLoaded;
	bool currentLevelStarCoinCollected;
	

};