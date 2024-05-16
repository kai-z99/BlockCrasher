#include "CoinItem.h"
#include "Player.h"
#include "LevelHandler.h"
#include "SoundManager.h"


CoinItem::CoinItem(float x, float y)
{
	this->isCollected = false;
	this->currentPosition = { x,y };
	this->hitboxRadius = 11.0f;
	this->animationState = 1;
	this->type = Coin;
}

bool CoinItem::CheckCollision(Player* p)
{
	return CheckCollisionCircles({ p->GetPosX(), p->GetPosY() }, p->GetHitboxRadius(), {this->currentPosition.x, this->currentPosition.y}, this->hitboxRadius);
}

void CoinItem::Draw()
{
	// Offset y for animation state
	float yOffset = 0;

	switch (this->animationState)
	{
	case 1:
		yOffset = 0.0f;
		break;

	case 2:
		yOffset = 1.5f;
		break;

	case 3:
		yOffset = 3.0f;
		break;

	case 4:
		yOffset = 4.0f;
		break;

	case 5:
		yOffset = 3.0f;
		break;

	case 6:
		yOffset = 1.5f;
		break;
	}


	DrawRingLines({ this->currentPosition.x, this->currentPosition.y - yOffset * 1.5f }, 3, this->hitboxRadius, 0, 320, 6, YELLOW);
}

void CoinItem::Update(unsigned int frame, Player* p, LevelHandler* levelHandler, SoundManager* soundManager)
{
	// Check if coin is collected
	if (this->CheckCollision(p) && this->isCollected == false)
	{
		this->isCollected = true;
		levelHandler->AddCoinsCollected(1);
		soundManager->PlaySoundFile(1);
	}

	//update animation state
	if (levelHandler->GetCurrentLevelFramecount() % 10 == 0)
	{
		this->animationState += 1;

		if (this->animationState > 6)
		{
			this->animationState = 1;
		}
	}
}
