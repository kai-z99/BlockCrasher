#include "StarCoin.h"
#include "LevelHandler.h"
#include "SoundManager.h"
#include "SoundEffect.h"

StarCoin::StarCoin(float x, float y) : CoinItem(x, y)
{
	this->hitboxRadius = 16.0f;

}

void StarCoin::Draw()
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


	DrawRingLines({ this->currentPosition.x, this->currentPosition.y - yOffset * 2.0f }, 5, this->hitboxRadius, 0, 320, 8, PINK);
}

void StarCoin::Update(unsigned int frame, Player* p, LevelHandler* levelHandler, SoundManager* soundManager)
{
	// Check if coin is collected
	if (this->CheckCollision(p) && this->isCollected == false)
	{
		levelHandler->currentLevelStarCoinCollected = true;
		this->isCollected = true;
		soundManager->PlaySoundFile(StarCoinCollect);
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



