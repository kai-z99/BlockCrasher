#include "Item.h"

Vector2 Item::GetCurrentPosition() const
{
	return this->currentPosition;
}

ItemType Item::GetItemType() const
{
	return this->type;
}

void Item::SetPosition(Vector2 pos)
{
	this->currentPosition = pos;
}
