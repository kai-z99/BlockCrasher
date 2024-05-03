#pragma once
#include <vector>
#include <memory>
#include <raylib.h>

class Obstacle;
class Player;
class CollisionManager;
class PlayerMovementHandler;
class LevelHandler;


class Game
{
private:
	unsigned int frameCount;
	void Init();
	void Draw();
	void Update(unsigned int frame);
	void HandleInput();
	void HandleCollisions();
	void HandleLevel();

protected:
	Player* player;
	std::vector<Obstacle*> activeObstacles;
	CollisionManager* collisionManager;
	PlayerMovementHandler* movementHandler;
	LevelHandler* levelHandler;

public:
	Game();
	void Run();

};