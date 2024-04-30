#pragma once

class Player;

class PlayerMovementHandler
{
public:
	PlayerMovementHandler();
	void HandlePlayerMovement(Player* p);
};