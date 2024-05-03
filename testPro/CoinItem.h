#pragma once
#include "Item.h"

class Player;
class LevelHandler;

class CoinItem : public Item
{
private:
	float hitboxRadius;
	int animationState;
	bool CheckCollision(Player* p);
	
public:
	CoinItem(float x, float y);
	void Draw() override;
	void Update(unsigned int frame, Player* p, LevelHandler* levelHandler) override;

};