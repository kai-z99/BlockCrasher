#pragma once
#include <raylib.h>
#include "ItemTypes.h"

class Player;
class LevelHandler;

class Item
{
protected:
	Vector2 currentPosition;
	ItemType type;
	
public:
	virtual void Update(unsigned int frame, Player* p, LevelHandler* levelHandler) = 0;
	virtual void Draw() = 0;
	Vector2 GetCurrentPosition() const;
	ItemType GetItemType() const;
	void SetPosition(Vector2 pos);
	bool isCollected;
	


};