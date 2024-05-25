#pragma once
#include <vector>
#include <raylib.h>

class Obstacle;

class ObstacleBuilder
{
private:
	std::vector<Obstacle*> storage;
public:
	void Insert(std::vector<Obstacle*>& activeObstacles );
	void ClassicCircle(float x, float y, float r, Vector2 vi);
	void ClassicRectangle(float x, float y, float w, float h, Vector2 vi);

	void FlyingPentagon(float x, float y);
	void MasterSword(float x, float y);
	void HollowBoxPiece(float x, float y, float rr, float ri, float vo, float scale);
	void Wheel(float x, float y, float rr, float ri, float vo, float scale);
	void NinjaStar(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale);
	void RotatingBar(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale);
	void GridPiece(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale, Vector2 center);
	void Tree(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale);
	void Hook(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale);
	void VortexPiece(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale, Vector2 center);
	void Hammer(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale);
	void RainDrop(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale);
	void BattleShip(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale);
	void Anchor(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale);

};