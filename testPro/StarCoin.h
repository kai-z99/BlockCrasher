#pragma once
#include "CoinItem.h"

class StarCoin : public CoinItem
{
public:
	StarCoin(float x, float y);
	void Draw() override;
	void Update(unsigned int frame, Player* p, LevelHandler* levelHandler) override;
};