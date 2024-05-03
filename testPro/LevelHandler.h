#pragma once
#include <vector>

class Obstacle;
class ObstacleBuilder;

class LevelHandler
{
private:
	int currentLevel;
	ObstacleBuilder* obstacleBuilder;

public:
	LevelHandler();
	void LoadCurrentLevel(std::vector<Obstacle*>& activeObstacles);
	void UnloadCurrentLevel(std::vector<Obstacle*>& activeObstacles);
	void HandleCurrentLevel();
	void SetLevel(int l);


};