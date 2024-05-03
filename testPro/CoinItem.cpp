#include "CoinItem.h"
#include "Player.h"
#include "LevelHandler.h"

CoinItem::CoinItem(float x, float y)
{
	this->isCollected = false;
	this->currentPosition = { x,y };
	this->hitboxRadius = 5.0f;
	this->animationState = 0;
	this->type = Coin;
}

bool CoinItem::CheckCollision(Player* p)
{
	return CheckCollisionCircles({ p->GetPosX(), p->GetPosY() }, 5, { this->currentPosition.x, this->currentPosition.y }, 5);
}

void CoinItem::Draw()
{
	DrawRingLines({ this->currentPosition.x, this->currentPosition.y }, 3, 11, 0, 320, 6, YELLOW);
}

void CoinItem::Update(unsigned int frame, Player* p, LevelHandler* levelHandler)
{
	if (this->CheckCollision(p) && this->isCollected == false)
	{
		this->isCollected = true;
		levelHandler->AddCoinsCollected(1);
	}
}
