#pragma once
#include <vector>
#include <memory>
#include <raylib.h>

class Obstacle;
class Player;
class Item;
class CollisionManager;
class PlayerMovementHandler;
class GeneralInputHandler;
class LevelHandler;
class MenuHandler;


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
	std::vector<Item*> activeItems;
	CollisionManager* collisionManager;
	PlayerMovementHandler* movementHandler;
	GeneralInputHandler* inputHandler;
	LevelHandler* levelHandler;
	MenuHandler* menuHandler;

public:
	Game();
	void Run();

};